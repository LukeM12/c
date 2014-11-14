
#include "part2.h"


int main(void){
    char *a = strdup("\nStart Running Test Suit \n-----------------\n");
    printf("%s", a);
    //test creating a process
    // miniPCB *loc = testcreateminiProcess(3, b) ;
    
    //Test the creation of the file
    //int res = testReadInputFile("input.config");
    QueueList *pcbQueue = (QueueList*)malloc(sizeof(QueueList));

    if (pcbQueue == NULL){
        printf("Queue is NULL");
        return 0;
    }
    parseInputFile(readInputFile("input.config"), &pcbQueue);
    miniPCB* pcb;
    if (pcbQueue->start == NULL){
        printf("ERROR: the queue start is nulled");
    }
    pcb = pcbQueue->start;
    if (pcb== NULL){
        printf("ERROR: the queue is nulled");
    }
    printQueue(pcbQueue);
    int ret  = TRUE; 
    while (ret != FALSE){ 
        ret  = dispatchProcess(&pcbQueue);
    }
return 0;
    /* FILEIO TESTING */
}
    /* QUEUE TESTING */
    /*insert(&pcbQueue->start, &pcbQueue->end, 3,2,4,3,4);
    insert(&pcbQueue->start, &pcbQueue->end, 3, 4,5,3,4);
    int ret;
    printQueue(pcbQueue);
    delete(&pcbQueue->start, &pcbQueue->end, &ret);
    //printf("%s", pcbQueue->start->cpu_info);
    
    printQueue(pcbQueue);
    insert(&pcbQueue->start, &pcbQueue->end, 4, 3,2,5,4);
    insert(&pcbQueue->start, &pcbQueue->end, 3, 5,4,3,2);
    printf("The return value was %i", ret);
        printQueue(pcbQueue);
    if (index == 0)
        printf("Tests Succeeded\n\n");
    else
        printf("\nTest Failed! There Are %i Errors\n\n", index);*/

