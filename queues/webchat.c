#include<stdio.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<string.h>
#include <netinet/in.h>
#include<time.h>
#include "webchat.h"
/*
* This program makes both a server and a client at the same time
* (Over TCP/IP) It holds 2 queues that takes information about the
* networking transactions and processes them as necessary
*/

void main(){
    struct QueueList *client =  (struct QueueList*)malloc(sizeof(struct QueueList));
    char temp[5] = "192";
    int sockfd;
    int port = 233;
    int listenfd = 0; //This will be the socket 
    int connfd = 0;
    struct sockaddr_in serv_addr;
    
    /* Create a Socket point */
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0 ){
    	printf("Error opening socket");
    }
    
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(port);
        
}    /*int listenfd = 0;
    int connfd = 0;
    struct sockadd_in serv_addr;
    char sendBuff[1025];
    int numrv;
   	int valid ;
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    printf("Socket Retrieve Success \n");*/

   	/*valid = create_queue(client, NULL, 56, temp, NULL);
   	valid = create_queue(client, NULL, 4, temp, NULL);
   	valid = create_queue(client, NULL, 8, temp, NULL);
   	EnQueue(client);
   	printf("Queue Length = %i \n", client->length);
    EnQueue(client);
    EnQueue(client);*/
    
    
    /*
 Client Side
-Create a socket with the socket() system call
-Connect the socket to the address of the server using the connect() system call
-Send and receive data. There are a number of ways to do this, but the simplest is to use the read() and write() system calls.
-The steps involved in establishing a socket on the server side are as follows:





Server side 
-Create a socket with the socket() system call
-Bind the socket to an address using the bind() system call. For a server socket on the Internet, an address consists of a port number on the host machine.
-Listen for connections with the listen() system call
-Accept a connection with the accept() system call. This call typically blocks until a client connects with the server.

Send and receive data

   
    
    













































    /*printf("Print 2nd time \n");
    EnQueue(client);
    
    PrintQueue(client);
    printf("Print 3nd time \n");
    EnQueue(client);
     
    PrintQueue(client);
    printf("Print 4nd time \n");*/


    //Able to get a valid point for start Node, but not display the port number
    //Possibly, it is just a matter of fixing referencing modes
    //But this is how the Queue should be called for this project
    //Note for testing, the point is to make a structure and add it to the 
    //Queue, which paramters are filled out
    //Then
    //1)Pass the data flawlessly to the queue
    //2)Add more queue-like operatings, enqueue, deletequeue
    //3)Test Queueue operations
    //4)Set up sockets for data transfer
    //5)Start trading information test cases
    //6)Migrate that to python binding the C and python libraries 
    //7)Make GUI in python 
    //Starting with 2 queues, one for client and one for server


