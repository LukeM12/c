#include<stdio.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<string.h>
struct Node {
    char *title;
    int port;
    //IP
    char *sender;
    char *recvr;
    struct Node *first;
    struct Node *prev;
};

struct QueueList {
    struct Node *start;
    struct Node *end;
};
/*
* This function creates an empty queue
*/
int create_queue(struct QueueList *Queue, struct Node input) {
   // if (! (*Queue)->start) ){
        //struct Node temp;
        //temp = (struct Node *)malloc(sizeof(struct Node));
        //(*Queue)->start = temp;

}




void make_El( struct Node *temp, struct Node input ){
    //No need to re-create an already created Node
    if (temp != NULL){
            return;
    }
    temp = (struct Node *)malloc(sizeof(struct Node));
    if ( ! (temp) ){
        printf("ERROR : Element Memory Leak");
    }

    //Now copy the information into the newly made node
    if (input.title){
        temp->title = input.title;
    }
    if (input.port){
        temp->port = input.port;
    }
    if (input.sender){
        temp->sender = strdup(input.sender);
    }
    if (input.recvr){
        temp->recvr = strdup(input.recvr);
    }
    return;
}

/*
* This function makes a new element to be added to the queue
*/
/*
int add_queue(struct Node **head, struct Node input){
    if (!(*head)) {
        int temp = create_queue(head, input);
            return 1;
        }
    }
    struct Node *curr;
    curr = head);

    int temp = create_queue(&curr, input);


    if (input.title) {
        curr->title = input.title;
    }
    if (input.port) {
        curr->port = input.port;
    }
    if (input.sender) {
        curr->sender = input.sender;
    }
    if (input.recvr) {
        curr->recvr = input.recvr;
    }

    curr->next =
    curr->prex =
    return 1;
}
*/
/*
* This program makes both a server and a client at the same time
* (Over TCP/IP) It holds 2 queues that takes information about the
* networking transactions and processes them as necessary
*/

void main(){
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
    struct QueueList clsrv;

    //Some test data
    char temp[5] = "192";
    struct Node inputNode;
    inputNode.sender = strdup(temp);
    printf("%s\n", inputNode.sender);

    struct Node temper;
    make_El( &temper, inputNode);
    printf("%s", temper.sender);
  //  create_queue(  &(clsrv.start) , inputNode);
   //Now clsrv[0] should had a queue head and be initialized to whatever
    //was in inputNode
   // printf("%s\n", clsrv.start->sender);
    //Ok so we are able to take parameters TODO test other parameters
    //mAKE QUEUE OPERATIONS


}

