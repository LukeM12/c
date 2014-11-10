
#include "part2.h"


int main(void){
    char *a = strdup("\nStart Running Test Suit \n-----------------\n");
    printf("%s", a);

    char *b = strdup("CPU-INFO");

    //test the creation of a new process
    miniPCB *loc = testcreateminiProcess(3, b) ;
    //Test the creation of the file
    int res = testReadInputFile("input.config");
    //res = testparseInputFile();
    QueueList *pcbQueue = (QueueList*)malloc(sizeof(QueueList));

    if (pcbQueue == NULL){
        printf("Queue is NULL");
        return 0;
    }


    //pcbQueue->start = createminiProcess(2,"CPU-Info");
   // miniPCB *in = createminiProcess(2,"CPU-Info"); 
    //res = enQueue(pcbQueue->start, pcbQueue->end, "CPU", 47);
    insert(&pcbQueue->start, &pcbQueue->end, 1, "intel-i3");
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
    
    
    
    
    
    //   enQueue(&pcbQueue ,createminiProcess(5,"intel i5"));
   // if (pcbQueue.start == NULL){
    //    printf("Start is nulled");
    //}

    //printf("%s", pcbQueue.start->cpu_info);
    if (index == 0)
        printf("Tests Succeeded\n\n");
    else
        printf("\nTest Failed! There Are %i Errors\n\n", index);

    return 0;
}


 /*         Memory Creation         */
miniPCB *createminiProcess(int pid, char *type){
    miniPCB *pcb ;
    pcb = (miniPCB*)malloc(sizeof(miniPCB));
    if (pcb == NULL){
        error_flag[index]= ERROR_PCBCREATION;
        index++;
        //return NULL;
    }
    pcb->pid = pid;
    pcb->cpu_info = strdup(type);
    if (pcb->cpu_info == NULL){
        error_flag[index] = ERROR_PCBCREATION;
        index++;
        //return NULL;
    }

    return pcb;
}


//boolean
int isReady(miniPCB pcb){
    return FALSE;
}
int isRunning(miniPCB pcb){
    return FALSE;
}

int isWaiting(miniPCB pcb){
    return FALSE;

}

int isTerminated(miniPCB pcb){
    return FALSE;

}

float getTime(miniPCB pcb){
    return 0.0;
}

char **parseInputFile(FILE *inFile){
    char *localString;
    size_t len = 0;
    int bytes_read=0;
    while (bytes_read != -1 && localString[0] != '}') {
        bytes_read = getline(&localString, &len, inFile);
        if (read == -1){
            error_flag[index]= ERROR_FILEIO;
            index++;
            printf("\n%s\n", ERROR_FILEIO_out);
            return ERROR_FILEIO;
        }
        printf("\nthe character is %c\n",localString[0]);
    }
    return ;
}

FILE *readInputFile(char *fileString){
   
    FILE *file = fopen(fileString, "r");
    if (file == NULL){
        return NULL;
    }
    else return file;
}

