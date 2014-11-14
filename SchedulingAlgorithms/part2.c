
#include "part2.h"
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

void parseInputFile(FILE *inFile, QueueList **queuePCB){
    char *localString;
    size_t len = 0;
    int bytes_read=0;
    char *token;
    const char s[2] = ":";

    //An array to hold the file inputs
    char ret[5 * MAX_PROCESS][15];
    //read the file line by line 
    while (bytes_read != -1 && localString[0] != '}') {
        bytes_read = getline(&localString, &len, inFile);
        if (read == -1){
            error_flag[index]= ERROR_FILEIO;
            index++;
            printf("\n%s\n", ERROR_FILEIO_out);
            return ERROR_FILEIO;
        }

        //tokenize the string to isolate input 
        token = strtok(localString, s);

        //These are the attributes of the incoming process to be parsed
        int pid = -1;
        int arrival = -1;
        int cpu_time = -1;
        int frequency = 3;
        int ioduration = 4;
        char *cpu_info = NULL;
        int remaining_time = 0;

        //Check the kind of string and put it in the queue 
        while( token != NULL ) {
            if ( (strcmp(token, "pid") == 0)){
                token = strtok(NULL, s);
                printf("The token is this : %s", token);
                printf("\tAdded to 5 is this=%i\n", atoi(token)+5);
                pid = atoi(token);
            }
            if ( (strcmp(token, "arrival") == 0)){
                token = strtok(NULL, s);
                pid = atoi(token);
            }

            else if ( (strcmp(token, "cputime") == 0)){
                token = strtok(NULL, s);
            }

            else if ( (strcmp(token, "frequency") == 0)){
                token = strtok(NULL, s);
            }

            else if ( (strcmp(token, "ioduration") == 0)){
                token = strtok(NULL, s);
            }

            //printf( " %s\n", token );
            token = strtok(NULL, s);

        }
        //INsert the chunk from the file intoi a process
        insert(&(*queuePCB)->start, &(*queuePCB)->end, atoi(token), "i3-CPU");

    }
    return ;
}

FILE *readInputFile(char *fileString){
   
    FILE *file = fopen(fileString, "r");
    if (file == NULL){
        error_flag[index]= ERROR_FILEIO;
        index++;
        printf("\n%s\n", ERROR_FILEREAD_out);
        return ERROR_FILEREAD;
    }
    else return file;
}


