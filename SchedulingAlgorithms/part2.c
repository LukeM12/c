/*
 * Author : Luke Morrison
 * Contact : luc785@hotmail.com
 * Date Created : Nov 8th 2014 
 * Last updated : 
 * Description - Program to schedule processes concurrently using several kinds of algorithms and benchmarks
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <semaphore.h>
#include <fcntl.h>

#define TRUE 1
#define FALSE 0

#define MAX_PROCESS 2

#define DISPATCH 3

#define ERROR_DEADLOCK 0x86
#define ERROR_LOOP 0x87
#define ERROR_NOEXIT 0x88
#define ERROR_PCBCREATION 0x89
#define ERROR_PCBCREATION_out "ERROR: PCB CREATION FAIL"
#define MAX_ERROR 10
/* A mini process control block that holds the state of the process */
typedef struct {
    int pid;
    char *cpu_info;
    int remaining_time;
} miniPCB; 

int index = 0;
int error_flag[MAX_ERROR]; 

/**
 * Description: Create a new process 
 * @param: int pid, char * Cpu model #
 * return an instance of the process block
 */
miniPCB *createminiProcess(int, char *);
int testcreateminiProcess(int, char *);
/**
 * Description:Terminate an existing process
 * @param: miniPCB an pcb block
 * return if the pcb got terminated or not 
 */
int terminateminiProcess(miniPCB *);
int testterminateminiProcess(miniPCB*);

/**
 * Description:Checks to see if the process is ready
 * @param: miniPCB
 * return TRUE of FALSE if it is ready or not
 */
int isReady(miniPCB);
int testisReady(miniPCB);
/**
 * Description: Checks to see if a process is running 
 * @param: miniPCB process block
 * return if it is running or not 
 */
int isRunning(miniPCB);
int testisRunning(miniPCB);

/**
 * Description: Checks to see if this process is waiting
 * @param: miniPCB process block 
 * return if the process is waiting or not
 */
int isWaiting(miniPCB);
int testIsWaiting(miniPCB);

/**
 * Description: Checks to see if the process has effectively terminated
 * @param: miniPCB process block
 * return if it is terminated
 */
int  isTerminated(miniPCB);
int  testisTerminated(miniPCB);
/**
 * Description: get the amount of time that it has been running
 * @param: miniPCB process block
 * return how long the process has been running for 
 */
float getTime(miniPCB);
int testgetTime(miniPCB);
/**
 * Description:  Parse the input file into a string array
 * @param: A active filestream instance
 * return a double array of the contents 
 //That double array should be a linked list instead of a key value pair 
 */
char **parseInputFile(FILE *);
int testparseInputFile(FILE *);
/**
 * Description: read the input file and return the File instance
 * @param: a string of the filename
 * return the file in stance
 */
FILE *readInputFile(char *);
int testReadInputFile(char*);

int main(void){
    char *a = strdup("\nStart Running Test Suit \n-----------------\n");
    printf("%s", a);
    //test the creation of a new process
    miniPCB *loc = testcreateminiProcess(3, a) ;
    if (index == 0)
        printf("Tests Succeeded\n\n");
    else
        printf("Test Failed! There Are %i Errors", index);

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
    return NULL;
}

int testparseInputFile(FILE *inFile){
    return NULL;
}

FILE *readInputFile(char *fileString){
    return NULL;
}

int testReadInputFile(char *fileString){
    return NULL;
}








