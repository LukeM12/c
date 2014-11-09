
#include "part2.h"


int main(void){
    char *a = strdup("\nStart Running Test Suit \n-----------------\n");
    printf("%s", a);

    //test the creation of a new process
    miniPCB *loc = testcreateminiProcess(3, a) ;
    //Test the creation of the file
    int res = testReadInputFile("input.config");
    res = testparseInputFile();
    QueueList pcbQueue;
    enQueue(&pcbQueue ,createminiProcess(5,"intel i5"));
    if (pcbQueue.start == NULL){
        printf("Start is nulled");
    }

    printf("%s", pcbQueue.start->cpu_info);
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
        return NULL;
    }
    pcb->pid = pid;
    pcb->cpu_info = strdup(type);
    if (pcb->cpu_info == NULL){
        error_flag[index] = ERROR_PCBCREATION;
        index++;
        return NULL;
    }

    return pcb;
}

int testcreateminiProcess(int pid, char *type){
    miniPCB *pcbObject ;
    //Create a mini process and check its fields
    pcbObject= createminiProcess(2, "i3-DualCore");
    if (pcbObject == NULL){
        error_flag[index]= ERROR_PCBCREATION;
        index++;
    }
    if (pcbObject->pid != 2){
        error_flag[index]= ERROR_PCBCREATION;
        printf("\n%s\n", ERROR_PCBCREATION_out);
        index++;
        return ERROR_PCBCREATION; 
    }
    pcbObject= createminiProcess(4, "i7-QuadCore");
    if (pcbObject == NULL){
        error_flag[index]= ERROR_PCBCREATION;
        index++;
        printf("\n%s\n", ERROR_PCBCREATION_out);
        return ERROR_PCBCREATION; 
    }
    if (pcbObject->pid != 4){
        error_flag[index]= ERROR_PCBCREATION;
     
        index++;
        printf("\n%s\n", ERROR_PCBCREATION_out);
        return ERROR_PCBCREATION; 
    }
    //Create another mini process and check its fields
    free(pcbObject);
    return ;
}

int createQueue(QueueList **head, miniPCB input) {
    return 1;
}

int enQueue(QueueList *input){ 
    if(input->start == NULL){
        input->start = input;
        input->end = input;
    }
    else{
        input->end = input;
    }
    return TRUE;
}

miniPCB deQueue(QueueList **input){
    miniPCB *deq= (*input)->start->next;
    (*input)->start->next = (*input)->start->prev;    
    free(deq);
}


//boolean
int isReady(miniPCB pcb){
    return FALSE;
}
int testisReady(miniPCB pcb){
    return FALSE;
}

int isRunning(miniPCB pcb){
    return FALSE;
}

int testisRunning(miniPCB pcb){

    return FALSE;
}


int isWaiting(miniPCB pcb){
    return FALSE;

}
int testIsWaiting(miniPCB pcb){
    return FALSE;

}

int isTerminated(miniPCB pcb){
    return FALSE;

}

int testisTerminated(miniPCB pcb){
    return FALSE;
}

float getTime(miniPCB pcb){
    return 0.0;
}
int  testgetTime(miniPCB pcb){
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

int testparseInputFile(){
    FILE * inFile = readInputFile("input.config");
    char **a;
    a = parseInputFile(inFile);
    return NULL;
}

FILE *readInputFile(char *fileString){
   
    FILE *file = fopen(fileString, "r");
    if (file == NULL){
        return NULL;
    }
    else return file;
}

int testReadInputFile(char *fileString){
    FILE *testfile = readInputFile(fileString);
    if (testfile == NULL){
        error_flag[index]= ERROR_FILEIO;
        index++;
        printf("\n%s\n", ERROR_FILEIO_out);
        return ERROR_FILEIO;
    }
    close(testfile);
    return TRUE;
}
