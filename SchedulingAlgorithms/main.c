
#include "part2.h"


int main(void){
    char *a = strdup("\nStart Running Test Suit \n-----------------\n");
    printf("%s", a);

    //test the creation of a new process 
    char *b = strdup("i3-dualcore");
   // miniPCB *loc = testcreateminiProcess(3, b) ;
    
    //Test the creation of the file
    //int res = testReadInputFile("input.config");

    QueueList *pcbQueue = (QueueList*)malloc(sizeof(QueueList));

    if (pcbQueue == NULL){
        printf("Queue is NULL");
        return 0;
    }
    
    /* QUEUE TESTING */
    /*insert(&pcbQueue->start, &pcbQueue->end, 1, "intel-i3");
    insert(&pcbQueue->start, &pcbQueue->end, 2, "intel-i5");
    insert(&pcbQueue->start, &pcbQueue->end, 3, "intel-i7");
    int ret;
    printQueue(pcbQueue);
    delete(&pcbQueue->start, &pcbQueue->end, &ret);
    //printf("%s", pcbQueue->start->cpu_info);
    
    printQueue(pcbQueue);
    insert(&pcbQueue->start, &pcbQueue->end, 4, "AMD64");
    insert(&pcbQueue->start, &pcbQueue->end, 3, "AMD32");
    printf("The return value was %i", ret);
        printQueue(pcbQueue);
    if (index == 0)
        printf("Tests Succeeded\n\n");
    else
        printf("\nTest Failed! There Are %i Errors\n\n", index);
*/
    /* FILEIO TESTING */
    parseInputFile(readInputFile("input.config"), &pcbQueue);
    printQueue(pcbQueue);

    return 0;
}
