 #include <getopt.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <stdio.h>
 #include <string.h>
 #include <errno.h>
 #include <assert.h>
 #include <signal.h>
 #include "cachelab.h"
 #include <math.h>

 /**
Eberto Ruiz - eruiz
Somto U - suzoegwu

cache lab - 3/31/17 


*/

//Variable to hold the integrity of the stack
int hit_count;
int miss_count;
int eviction;
int verbosity;
int numSets;
int set_bits, associativity, block_bits;
char* trace_file;
unsigned int set_index, tag;

//Line information
typedef struct constr{
  int LRU;
  int valid;
  int tag;
}constr;

//prints cache
void printUsage (char* argv[])
{
printf("Usage: %s [-hv] -s <num> -E <num> -b <num> -t <file>\n", argv[0]);
printf("Options:\n");
printf(" -h Print this help message.\n");
printf(" -v Optional verbose flag.\n");
printf(" -s <num> Number of set index bits.\n");
printf(" -E <num> Number of lines per set.\n");
printf(" -b <num> Number of block offset bits.\n");
printf(" -t <file> Trace file.\n");
printf("\nExamples:\n");
printf(" linux> %s -s 4 -E 1 -b 4 -t traces/yi.trace\n", argv[0]);
printf(" linux> %s -v -s 8 -E 2 -b 4 -t traces/yi.trace\n", argv[0]);
}

//processos information in file
void process_options(int argc, char* argv[]) {
char flagchar;
verbosity = 0;
set_bits = 0;
associativity = 0;
block_bits = 0;
trace_file = NULL;
while ((flagchar = getopt(argc,argv,"s:E:b:t:vh")) != -1) {
switch (flagchar) {
case 's':
set_bits = atoi(optarg);
break;
case 'E':
associativity = atoi(optarg);
break;
case 'b':
block_bits = atoi(optarg);
break;
case 't':
trace_file = optarg;
break;
case 'v':
verbosity = 1;
break;
case 'h':
printUsage(argv);
exit(0);
default:
printUsage(argv);
exit(1);
}
}
if (set_bits == 0 ||
associativity == 0 ||
block_bits == 0 ||
trace_file == NULL) {
printf("Missing required argument.\n");
printUsage(argv);
exit(1);
}
}

//simulates cache
void simulator(constr cache[numSets][associativity]){
  //values for the LRU, when it occurs whether I evict or hit
  int LRUindex, LRUval, evict, iHit;
  //keeps track of whether we hit
  int hit = 0;
  //goes through the lines and see whether we hit or not.
  //To see whether we hit, we check the tag of the cache and the input
  for(int i = 0;  i < associativity; i++){
    if(cache[set_index][i].valid == 1 && cache[set_index][i].tag == tag){
      iHit = i;
      hit = 1;
    }else{
      cache[set_index][i].LRU++;
    }
  }
  //if it wasnt a hit, update the miss count, eviction  becames true
  //and LRU index and val are updated
  if (hit == 0){
    miss_count++;
    evict = 1;
    LRUindex = 0;
    LRUval = -1;
    //we go through the associativity and if our valid bit is 0
    //we set the lines parameters over and eviction becomes false
    for(int i = 0; i < associativity; i++){
      if(cache[set_index][i].valid == 0){
        cache[set_index][i].LRU = 0;
        cache[set_index][i].tag = tag;
        cache[set_index][i].valid = 1;
        evict = 0;
        break;
      }

      //LRUVal is compared to current cache's LRU. If out value is smaller
      //we must update it in our cache as well as update the position it is at
      if(LRUval < cache[set_index][i].LRU){
        LRUval = cache[set_index][i].LRU;
        LRUindex = i;
      }
    }

    //if we have to evict then the eviction count gets incremented
    //and the position were the LRU is at must be updated with the passed values
    if(evict == 1){
      eviction++;
      cache[set_index][LRUindex].LRU = 0;
      cache[set_index][LRUindex].tag = tag;
      cache[set_index][LRUindex].valid = 1;
    }
  }
//else update the hit count
//and set the LRU at the hit location to 0
//this helps us find the LRU
  else {
    hit_count++;
    cache[set_index][iHit].LRU = 0;
  }
}


//main method
int main(int argc, char *argv[]) {
  //run process options to get the values of the cache
  process_options(argc, argv);
  unsigned int a;
  //gets the number of sets needed for the cache
  numSets = pow(2.0, set_bits);
  //creates the cache which is a 2D array of lines
  constr cache[numSets][associativity];
  //populates the cache with lines and values of the lines
  for(int i = 0; i < numSets; i++){
    for(int j = 0; j < associativity; j++){
      cache[i][j].valid = 0;
      cache[i][j].LRU = 50000;
      cache[i][j].valid = 0;
    }
  }
//input line to store the information in the cache
char inputline[100];
//reads the file
FILE* trace_file_pointer = fopen(trace_file, "r");


if (!trace_file_pointer) {
fprintf(stderr, "%s: %s\n", trace_file, strerror(errno));
exit(1);
}

//while reading the lines simulate what a cache should do depending on the values
while (fgets(inputline, 100, trace_file_pointer) != NULL) {
  if(inputline[0] == ' '){
    sscanf(inputline + 3, "%16x[^,]", &a);
    //masks to extract values for the set and tag indices
    unsigned int setMask = ~((-1) << set_bits);
    unsigned int tagMask = ((-1) << (set_bits + block_bits));
    //uses the masks to get the set and tag from the trace file
    set_index = (a >> block_bits) & setMask;
    tag = (a & tagMask);
    //Load values triggers a simulation of the cache
    if(inputline[1] == 'L'){
      simulator(cache);
    }
    //store values triggers a simulation of the cache
    else if(inputline[1] == 'S'){
      simulator(cache);
    }
    //Modify values  triggers two simulation of the cache
    else if(inputline[1] == 'M'){
      simulator(cache);
      simulator(cache);
    }

  }
}

//print the summary
printSummary(hit_count, miss_count, eviction);
//close the file reader
fclose(trace_file_pointer);
  return 0;
}
