#include <stdio.h>
#include "csapp.h"

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


void connect_client(int connfd, char* hostname, char *port, char *path, char* http_header){
  int clientfd;
  size_t n;
  char buf[MAXLINE];
  rio_t rio;
  clientfd = Open_clientfd(hostname, port);
  Rio_readinitb(&rio, clientfd);
    Rio_writen(clientfd, http_header, strlen(http_header));
    Rio_writen(clientfd, connectAccept, strlen(connectAccept));
    Rio_writen(clientfd, Proxy_connection, strlen(Proxy_connection));

   while ((n = Rio_readlineb(&rio, buf, MAXLINE)) != 0) {
        Rio_writen(connfd, buf, n);
        Fputs(buf, stdout);
    }
    Close(clientfd);
}

void* parse_URL(int *connfd){
  size_t n;
  rio_t rio;
  char buf[MAXLINE];

  char address[MAXLINE];
  char GET[10];
  char GETspace[100] = "GET ";
  char instructionSpace[100] = " HTTP/1.0 \n\r\n";
  char instruction[10];
  char portholder[100];
  char *target;
  char *hostname;
  char *path;
  char *port;
  char *http_header;
  char hostholder[MAXLINE];
  char *tempHost;
  char *tempPort;
  char defaultPort[10] = "80";
  char *intermediatePort;
  size_t pathLength = 0;
  size_t tempPortLength = 0;
  size_t tempHostLength = 0;
  size_t hostPortDiff = 0;
  size_t portPathDiff = 0;
  size_t hostPathDiff = 0;


   Rio_readinitb(&rio, *connfd);

   if((n = Rio_readlineb(&rio, buf, MAXLINE)) != 0) {
       printf("server received %d bytes\n", (int)n);
     sscanf(buf, "%s %s %s", GET, address, instruction);
     printf("ADDRESS BEFORE EVERYTHING %s\n", address);
     if (address[0] == 'h'){
       tempHost = address + 7;
     }else if(address[0] == 'w'){
       tempHost = address + 0;
     }

     //tempHost = address[7];
     printf("TempHost Before Everything %s\n", tempHost);
     //wHost= strtok(tempHost, "www.");
     //printf("WHost Before Everything %s\n", wHost);
     //if (wHost != NULL)
       tempHostLength = strlen(tempHost);
       tempPort = strstr(tempHost, ":");
       printf("temp Port is = %s\n", tempPort);
       if(tempPort != NULL){
         printf("INTER IS = %s\n", intermediatePort);
         intermediatePort = tempPort + 1;

         tempPortLength = strlen(tempPort);
         hostPortDiff = tempHostLength - tempPortLength;

         strncpy(hostholder, tempHost, hostPortDiff);


         path = strstr(intermediatePort, "/");


         if (path != NULL){
           pathLength = strlen(path);
           portPathDiff = tempPortLength - pathLength - 1;
           strncpy(portholder, intermediatePort, portPathDiff);

         }else{

           port = intermediatePort;

         }

       }else{
         printf("INTER IS else = %s\n", intermediatePort);
         port = "80";
         strncpy(portholder, defaultPort, 2);
         //portholder = "80";
         printf("Port should be = %s\n", port);
         path = strstr(tempHost, "/");

         pathLength = strlen(path);
         hostPathDiff = tempHostLength - pathLength;
         strncpy(hostholder, tempHost, hostPathDiff);

       }

     target = strcat(GETspace, path);
     http_header = strcat(target, instructionSpace);
     hostname = hostholder;
     port = portholder;
     printf("Host is = %s\n", hostname);
     printf("Port is = %s\n", port);
     printf("Path is = %s\n", path);
     printf("GET request = %s\n", http_header);
     connect_client(*connfd, hostname, port, path, http_header);
}


return 0;
}


int main(int argc, char **argv) {
    pthread_t thread;
    printf("%s", user_agent_hdr);
    int listenfd;
    int *connfd;
    int hey;
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
        Pthread_create(&thread, NULL, parse_URL, (void*)connfd);
        Pthread_detach(thread);
        //echo(connfd, hostname, port, path);
        //parse_URL(hostname, port, path, connfd);

    }
    Close(*connfd);
    exit(0);
}
