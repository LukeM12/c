#include "part2.h"
int createQueue(QueueList **head, miniPCB input) {
    return 1;
}

void insert(miniPCB **front, miniPCB **rear, int value, char *cpu_info)
{
   miniPCB *temp;
   temp=createminiProcess(value, cpu_info);
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
/* */
  
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


void printQueue(QueueList *input){
    miniPCB *yop = input->start;
    while( yop != NULL){
        printf("\nCPU=%s\tpid=%i", yop->cpu_info,yop->pid);
        yop = yop->next;
    }
    printf("\n");
}
