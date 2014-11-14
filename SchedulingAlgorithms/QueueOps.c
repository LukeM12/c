/*
 * Author : Luke Morrison
 * Contact : luc785@hotmail.com
 * Date Created : Nov 8th 2014 
 * Last updated : 
 * Description - This QueueOps.c handles all of the queue operations 
*/
#include "part2.h"

/*         Memory Creation         */
/**
 * Description: Create a new process 
 * @param: int pid , The process ID 
 * @param: int arrival, the time at which the process arrives 
 * @param: int cputime, the how long the process can go on for 
 * @param: int frequency, the frequency of this process
 * @param: int ioduration, the duration of IO that it needs
 * return an instance of the process block
 */
miniPCB *createminiProcess(int pid, int arrival, int cputime, int frequency, int ioduration){
    miniPCB *pcb ;
    pcb = (miniPCB*)malloc(sizeof(miniPCB));
    if (pcb == NULL){
        error_flag[index]= ERROR_PCBCREATION;
        index++;
        //return NULL;
    }
    pcb->pid = pid;
    pcb->arrival = arrival;
    pcb->cputime = cputime;
    pcb->frequency = frequency;
    pcb->ioduration = ioduration;
    pcb->next = NULL;
    return pcb;
}

/**
 * Description: Create a new process 
 * @param: miniPCB** front - the front of the queue
 * @param: miniPCB** read - the rear of the queue
 * @param: int pid , The process ID 
 * @param: int arrival, the time at which the process arrives 
 * @param: int cputime, the how long the process can go on for 
 * @param: int frequency, the frequency of this process
 * @param: int ioduration, the duration of IO that it needs
 * return by reference an updated queue
 */
void insert(miniPCB **front, miniPCB **rear, int pid, int arrival, int cputime, int frequency, int ioduration)
{
   miniPCB *temp;
   temp=createminiProcess(pid, arrival, cputime, frequency, ioduration);
   if(temp==NULL) {
      printf("No Memory available Error\n");
      exit(0);
   }

   if(*rear == NULL) {
      *rear = temp;
      *front = *rear;
   }
   
   else{
      (*rear)->next = temp;
      *rear = temp;
   }
}
/**
 * Description: Create a new process 
 * @param: miniPCB** front - the front of the queue
 * @param: miniPCB** read - the rear of the queue
 * @param & return : an id to be returned by reference
 */
void delete(miniPCB**front, miniPCB **rear, int *id)
{
   miniPCB *temp;
   if((*front == *rear) && (*rear == NULL))
   {
      printf(" The queue is empty cannot delete Error\n");
      exit(0);
   }
   *id = (*front)->pid;
   temp = *front;
   *front = (*front)->next;
   if(*rear == temp)
        rear = (*rear)->next;
   free(temp);
}

/**
 * Description : Print the Process Queue
 * @param: the QueueList
 */
void printQueue(QueueList *in){
    miniPCB * yop = in->start ;
    if (yop == NULL){
        printf("\nError: Cannot print Nulled Queue");
        return;
    }
    while( yop != NULL){
        printf("\npid=%i\narrival=%i\ncputime=%i\nfrequency=%i\nioduration=%i",yop->pid, yop->arrival, yop->cputime, yop->frequency, yop->ioduration);
        if (yop->next == NULL){
            yop = NULL;
        }
        else{
            yop = yop->next;
        }
    }
    printf("\n");
}
