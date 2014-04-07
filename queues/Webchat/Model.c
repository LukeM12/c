#include<stdio.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<string.h>
#include"webchat.h"

/*
 * This function creates an empty queue
 **/
int create_queue(struct QueueList *Queue, char *title, int port, char *sender, char *recvr) {
		if (!Queue->start){
			struct Node *temp;
			temp = make_El(title,port, sender, recvr);
			if (!temp){
				printf("New Node not created\n");
				return 1;
			}
            //Need to use Queue because the reference lives there
			Queue->end = temp;
			Queue->end->next = NULL;
			Queue->start = Queue->end;
			Queue->length = 1;
			return 1;
		}
		struct Node *temp;
		//Create the memory block
		temp = make_El(title,port, sender, recvr);
		if (!temp){
				printf("New Queue Not Added");
				return 1;
		}
		struct Node *end;
		end = Queue->end;
		end->next= temp;
		temp->prev = end;
		Queue->end = end->next; //or temp
		Queue->length++;
		return 1;
	}
/*
 * Enqueue an event
 **/
int EnQueue(struct QueueList *Queue) {
		if (!Queue->start){
			printf("Queue is empty\n");
			return 1;
		}
		struct Node *start = Queue->start;
		struct Node *temp = Queue->start;
		Queue->start = Queue->start->next;
		free(temp);
		Queue->length--;
        return 1;
}
/*
 * Make an Element
 **/
struct Node *make_El(char *title, int port, char *sender, char *recvr ){
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    if ( ! (temp) ){
        printf("ERROR : Element Memory Leak\n");
    }
    //Now copy the information into the newly made node
    if (title){
        temp->title = strdup(title);
    }
    if (port){
        temp->port = port;
    }
    if (sender){
        temp->sender = strdup(sender);
    }
    if (recvr){
        temp->recvr = strdup(recvr);
    }
    return temp;
}

void PrintQueue(struct QueueList* Queue){
	struct Node *temp = Queue->start;
	while(temp){
		printf("The port is %i\n", temp->port);
		temp = temp->next;
	}
	printf("\n");
}
