#include "part2.h"
int dispatchProcess(QueueList **queuePCB){
    int id;
    miniPCB *top = (*queuePCB)->start;
    if (top != NULL){
        (*queuePCB)->start->running= TRUE;
        printf("\nDispatching process %i for %i seconds\n", top->pid, top->ioduration);
        sleep(top->ioduration);
    } 
    else {
        return FALSE;
    }
    delete(&(*queuePCB)->start,&(*queuePCB)->end, &id);
    printf("Process %i has been run\n", id);
    return TRUE;
}
//boolean
int isReady(miniPCB pcb){
    return FALSE;
}
int isRunning(miniPCB *pcb){
    if (pcb->running == TRUE){
        return TRUE;
    }
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
    int pid = -1;
    int arrival = -1;
    int cpu_time = -1;
    int frequency = 3;
    int ioduration = 4;
    char *io_info = NULL;
    char *cpu_info = NULL;
    int remaining_time = 0;
    
    while (bytes_read != -1 && localString[0] != '}') {
        bytes_read = getline(&localString, &len, inFile);
        while (localString[0] != '$' && localString[0] != '}' && localString[0] != '{' ) {
            if (read == -1){
                error_flag[index]= ERROR_FILEIO;
                index++;
                printf("\n%s\n", ERROR_FILEIO_out);
                return ERROR_FILEIO;
            }
            //tokenize the string to isolate input 
            token = strtok(localString, s);
            //These are the attributes of the incoming process to be parsed
            while( token != NULL ) {
                if ( (strcmp(token, "pid") == 0)){
                    token = strtok(NULL, s);
                    //printf("\n I am in PID world");
                    pid = atoi(token);
                }
                if ( (strcmp(token, "arrival") == 0)){
                    //printf("\n I am in arrival world");
                    token = strtok(NULL, s);
                    arrival = atoi(token);
                }
                else if ( (strcmp(token, "cputime") == 0)){
                    //printf("\n I am in cputime world");
                    token = strtok(NULL, s);
                    cpu_time = atoi(token);
                }
                else if ( (strcmp(token, "frequency") == 0)){
                    //printf("\n I am in frequency world");
                    token = strtok(NULL, s);
                    frequency = atoi(token);
                }
                else if ( (strcmp(token, "ioduration") == 0)){
                    //printf("\n I am in ioduration world");
                    token = strtok(NULL, s);
                    printf("IODuration time = %i", atoi(token));
                    ioduration = atoi(token);
                }
                token = strtok(NULL, s);
                bytes_read = getline(&localString, &len, inFile);
            }
        }
        if ( pid != -1){
            insert(&(*queuePCB)->start, &(*queuePCB)->end, pid, arrival,cpu_time, frequency, ioduration);
            pid = -1;
        }
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


