#include <stdio.h>
#include "csapp.h"


/*
*
*Authors: Eberto Ruiz (eruiz) & Somto Uzoegwu (suzoegwu)
*
*/

/* Recommended max cache and object sizes */
#define MAX_CACHE_SIZE 1049000
#define MAX_OBJECT_SIZE 102400
#define HOST 0
#define USER_AGENT 1
#define CONNECTION 2
#define PROXY_CONNECTION 3
#define ACCEPT 4
#define ACCEPT_CONNECTION 5





/* You won't lose style points for including this long line in your code */
static const char *user_agent_hdr = "User-Agent: Mozilla/5.0 (X11; Linux x86_64; rv:10.0.3) Gecko/20120305 Firefox/10.0.3\r\n";
static char *connectAccept = "Connection: close\r\n";
static char *Proxy_connection = "Proxy-Connection: close\r\n";

/*Connecting to the client*/
void connect_client(int connfd, char* hostname, char *port, char *path, char* http_header){

  //client id
  int clientfd;
  size_t n;
  //length of buffer
  char buf[MAXLINE];
  rio_t rio;
  //grabs the client id
  clientfd = Open_clientfd(hostname, port);
  Rio_readinitb(&rio, clientfd);
  //writes to the client id
    Rio_writen(clientfd, http_header, strlen(http_header));
    Rio_writen(clientfd, connectAccept, strlen(connectAccept));
    Rio_writen(clientfd, Proxy_connection, strlen(Proxy_connection));
    //while we still have elements in the buffer, write to connect fd
   while ((n = Rio_readn(clientfd, buf, MAXLINE)) != 0) {
        Rio_writen(connfd, buf, n);

    }
  
    //close connfd
    Close(connfd);
    //close clientfd
    Close(clientfd);
}

//parse the URL
void* parse_URL(void *connectfd){
  int *connfd = (int *)connectfd;
  size_t n;
  rio_t rio;
  char buf[MAXLINE];
  //address to store the full url
  char address[MAXLINE];
  //stores the Get request
  char GET[10];
  char GETspace[100] = "GET ";
  //stores instruction
  char instructionSpace[100] = " HTTP/1.0 \n\r\n";
  char instruction[10];
  //stores the port number
  char portholder[100];
  //stores the path info along the GET info
  char *target;
  //sets the host
  char *hostname;
  //sets the path
  char *path;
  //sets the port
  char *port;
  //stores the complete http header
  char *http_header;
  //stores the host
  char hostholder[MAXLINE];
  char *tempHost;
  //stores a temporary port
  char *tempPort;
  char *intermediatePort;
  //default port number
  char defaultPort[10] = "80";

  //length sizes for different strings
  size_t pathLength = 0;
  size_t tempPortLength = 0;
  size_t tempHostLength = 0;
  //the difference between two strings
  size_t hostPortDiff = 0;
  size_t portPathDiff = 0;
  size_t hostPathDiff = 0;

  //read in connfd
   Rio_readinitb(&rio, *connfd);
   //read from buffer
   if((n = Rio_readlineb(&rio, buf, MAXLINE)) != 0) {
     //split the message into three
     sscanf(buf, "%s %s %s", GET, address, instruction);
     printf("address is = %s\n", address);
     //check if we are dealing with a http address of www
     if (address[0] == 'h'){
       tempHost = address + 7;
     }else if(address[0] == 'w'){
       tempHost = address + 0;
     }
      //get the length of the temphost
       tempHostLength = strlen(tempHost);
       //set the tempPort
       tempPort = strstr(tempHost, ":");
       //if there is a port
       if(tempPort != NULL){
         //get the value of the port
         intermediatePort = tempPort + 1;
         //get the length of the port
         tempPortLength = strlen(tempPort);
         //get the difference between the length of the port and the host
         hostPortDiff = tempHostLength - tempPortLength;
         //copy the amount needed for the full host over to a hostholder
         strncpy(hostholder, tempHost, hostPortDiff);

         //check if there is a path
         path = strstr(intermediatePort, "/");

         //if there is a path
         if (path != NULL){
           //get the length of the path and copy the path over
           pathLength = strlen(path);
           portPathDiff = tempPortLength - pathLength - 1;
           strncpy(portholder, intermediatePort, portPathDiff);

         }else{
           //else set the path to be nothing
           port = intermediatePort;


         }

       }else{
         //if no port set the value of the port to be 80
         port = "80";
         strncpy(portholder, defaultPort, 2);
         //find the path
         path = strstr(tempHost, "/");
         //get the length of the path
         pathLength = strlen(path);
         //get the difference between the host and the path and copy the host over
         hostPathDiff = tempHostLength - pathLength;
         strncpy(hostholder, tempHost, hostPathDiff);

       }
       //if there is a path
    if(path != NULL){
      //get the length of the path and copy the path over
     target = strcat(GETspace, path);
     http_header = strcat(target, instructionSpace);
   }else{
     //else set the path to be nothing
     http_header = strcat(GETspace, instructionSpace);
   }
    //set the host name
     hostname = hostholder;
     //set the port name
     port = portholder;
     printf("Host is = %s\n", hostname);
     printf("Port is = %s\n", port);
     printf("Path is = %s\n", path);
     printf("GET request = %s\n", http_header);
     //connect to the client
     connect_client(*connfd, hostname, port, path, http_header);
}


return 0;
}


int main(int argc, char **argv) {
  //My thread
    pthread_t thread;
    printf("%s", user_agent_hdr);
    int listenfd;
    int *connfd;
    socklen_t clientlen;
    struct sockaddr_storage clientaddr; /* room for any addr */
    char client_hostname[MAXLINE], client_port[MAXLINE];

    listenfd = Open_listenfd(argv[1]);
    while (1) {
        connfd = (int*)malloc(sizeof(int));
        clientlen = sizeof(struct sockaddr_storage); /* Important! */
        *connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen);
        Getnameinfo((SA *) &clientaddr, clientlen, client_hostname,
                    MAXLINE, client_port, MAXLINE, 0);
        printf("Connected to (%s, %s)\n", client_hostname, client_port);
        //creates a thread
        Pthread_create(&thread, NULL, parse_URL, (void*)connfd);
        Pthread_detach(thread);


    }
    Close(listenfd);
    Close(*connfd);
    exit(0);
}
