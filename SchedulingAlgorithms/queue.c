#include<stdio.h>
#include<sys/socket.h>
#include<stdlib.h>
#include "part2.h"

struct Node {
    char *title;
    int port;
    char *sender;
    char *recvr;
    struct Node *next;
    struct Node *prev;
};

struct queuelist {
    struct Node *start;
    struct Node *end;
};
/*
* This function creates an empty queue
*/
int create_queue(miniPCB **head, miniPCB input) {
    (*head) = (miniPCB*)malloc(sizeof(miniPCB));
    if (!(*head)){
        printf("ERROR : Queue not allocated");
    
    return 1;
}
/*
* This function makes a new element to be added to the queue
*/
int add_queue(struct Node **head, struct Node input){
    if (!(*head)) {
        int temp = create_queue(head, input);
            return 1;
        }
    }
    struct Node *curr;
    curr = (*head);
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
    return 1;
}

/*
* This program makes both a server and a client at the same time
* (Over TCP/IP) It holds 2 queues that takes information about the
* networking transactions and processes them as necessary
*/
/*void main(){
    struct queuelist in_out[2];
    char temp[5] = "hi th";
    char *copy = temp;
    printf("%c", copy[1]);
    strcpy(temp, copy);
    printf("%s\n", temp);
}*/

