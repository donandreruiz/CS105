/*
Eberto Ruiz - eruiz
Somtochukwu Uzoegwu - suzoegwu
*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define bSize 10

typedef struct message {
int value; /* value to be passed to consumer */
int consumer_sleep; /* time (in ms) for consumer to sleep */
int line; /* line number in input file */
int print_code; /* output code; see below */
int quit; /* non-zero if consumer should exit */
}message;

struct message buffer[bSize];


struct message *bufferPointer = buffer;

//set up the thread conditions and mutex
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t has_value = PTHREAD_COND_INITIALIZER;
pthread_cond_t has_space = PTHREAD_COND_INITIALIZER;


//amount of elements in buffer
int length;

//timer
struct timespec timer;

//gets the time that producer and consumer should sleep
void timeConverter(int *msecs){
  timer.tv_sec = (double)(*msecs)/1000;
  timer.tv_nsec = ((*msecs) * 100000) %  100000000;

  nanosleep(&timer, &timer);

}

//stores values into the buffer
void *producerFunction(){

  //local variables to store values in the file
int localVal;
int proSleep;
int consSleep;
int localCode;
int lineNum = 1;
int input = 0;


//stores value from file into buffer
while(scanf("%d %d %d %d", &localVal, &proSleep, &consSleep, &localCode) != EOF){
  //sleep if producer sleep is greater than 0
      if(proSleep >0){
       timeConverter(&proSleep);
    }
    //lock the mutex
      pthread_mutex_lock(&mutex);

      //if at max capacity, wait for open space
      while (length == bSize){
        pthread_cond_wait(&has_space, &mutex);

      }
      //update the length
      length++;

      //store all the values in the buffer
      (bufferPointer + input)->value = localVal;
      (bufferPointer + input)->consumer_sleep = consSleep;
      (bufferPointer + input)->line = lineNum;
      (bufferPointer + input)->print_code = localCode;

      //move the buffer pointer 1 over
      input = (input + 1) % bSize;

      //unlock the mutex
      pthread_mutex_unlock(&mutex);

      //signal that mutex is available
      pthread_cond_signal(&has_value);

      //print producer status
      if (localCode == 1 || localCode == 3){
        printf("Produced %d from input line %d\n", localVal, lineNum);
      }

      //update the line number
      lineNum++;
    }
    pthread_mutex_lock(&mutex);

    //if at max capacity, wait for open space
    while (length == bSize){
      pthread_cond_wait(&has_space, &mutex);

    }
      //pthread_mutex_lock(&mutex);
    //store the last quit message to be 1 with a value of zero and increment input and length
    (bufferPointer + input)->quit = 1;
    (bufferPointer + input)->value = 0;
    input = (input + 1) % bSize;
    length++;
    //pthread_mutex_unlock(&mutex);
    pthread_mutex_unlock(&mutex);

    //signal that mutex is available
    pthread_cond_signal(&has_value);

    //signal that mutex is available
    //pthread_cond_signal(&has_value);

    return NULL;
}

//record value from messages in buffer
void *consumerFunction(void *arg){
  int output = 0;

  //keeps track of the quit message
  int validate = 0;

  //tempMessage to remove message from buffer
  message tempMessage;

  //value counter
  int total;

  //displacement buffer counter
  output =0;

  //keep running while the quit field is zero
  while (validate == 0){
    //lock mutex so producer won't update the buffer
    pthread_mutex_lock(&mutex);

    //if there is nothing in the buffer, wait for the producer
    if(length == 0){
      pthread_cond_wait(&has_value, &mutex);
    }
    length--;

    //store the message from the buffer into a temporary message
    tempMessage = *(bufferPointer + output);

    //update the quit field
    validate = buffer[output].quit;



    //update total
      total += tempMessage.value;


//unlock the mutex
    pthread_mutex_unlock(&mutex);
    pthread_cond_signal(&has_space);

    //sleep if need consumer_sleep is greater than zero
      if(tempMessage.consumer_sleep>0){
      timeConverter(&tempMessage.consumer_sleep);
    }

    //print the consumer status
    if (tempMessage.print_code == 2 || tempMessage.print_code == 3){
      printf("Consumed %d from input line %d; sum = %d\n", tempMessage.value, tempMessage.line, total);
    }
    output = (output + 1) % bSize;


  }
  //print the final sum
  printf("Final sum is %d\n", total);
  return NULL;
}

int main (int argc, char *argv[]){

  //set up the consumer and producer threads
  setlinebuf(stdout);
  pthread_t consumer;
  pthread_t producer;

  //set the conditions and create the mutex
  pthread_mutex_init(&mutex, NULL);
  pthread_cond_init(&has_value, NULL);
  pthread_cond_init(&has_space, NULL);

  //create the consumer and producer threads
  pthread_create(&consumer, NULL, consumerFunction, NULL);
  pthread_create(&producer, NULL, producerFunction, NULL);

  //join the consumer and producer threads
 pthread_join(consumer, NULL);
 pthread_join(producer, NULL);

//exit
 exit(0);

}
