#include<stdio.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<string.h>
#include <netinet/in.h>
#include<time.h>
#include<sys/types.h>
#include "webchat.h"

//take these out they are not your image of the file
#define SERVER_PORT 1501
#define MAX_MESSAGE_SIZE 100

void main(int argc, char *argv[]){

    struct QueueList *client =  (struct QueueList*)malloc(sizeof(struct QueueList));
    char Buffer[1025];
    int sockfd;
    int port = 233; //
    int listenfd = 0; //This will be the socket
    int connfd = 0;
    time_t ticks;
    struct sockaddr_in local_addr, serv_addr;
    struct hostent *h; //what does this do?

    /* Just clear everything to zero for stability purposes */
    memset(&serv_addr, '0', sizeof(serv_addr));
    memset(Buffer, '0', sizeof(Buffer));

    /* Create a Socket point */
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0 ){
    	printf("Error opening socket");
    }


    /* bind server port */
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(SERVER_PORT);

	/*Now bind it to the port */

    if ( ! bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) ){
    	perror("Cannot bind port");
    }


	listen(listenfd, 10);
    /* Infinite loop to accept any invcoming traffic*/
	while(1)
    {
    	printf("%s: waiting for data on port TCP %u\n",argv[0],SERVER_PORT);
        connfd = accept(listenfd, (struct sockaddr*)NULL, NULL);

        ticks = time(NULL);
        snprintf(Buffer, sizeof(Buffer), "%.24s\r\n", ctime(&ticks));
        write(connfd, Buffer, strlen(Buffer));

        close(connfd);
        sleep(1);
     }


}

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


Here is an excerb from the man page of socket listen function
           1.  A socket is created with socket(2).

           2.  The  socket  is  bound  to  a local address using bind(2), so that
               other sockets may be connect(2)ed to it.

           3.  A willingness to accept incoming connections and a queue limit for
               incoming connections are specified with listen().

           4.  Connections are accepted with accept(2).


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


