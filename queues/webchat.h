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
    struct Node *next;
    struct Node *prev;
};

struct QueueList {
    struct Node *start;
    struct Node *end;
    int length;
};

struct Node *make_El(char *, int, char *, char *);

int EnQueue(struct QueueList *);
void PrintQueue(struct QueueList*);
