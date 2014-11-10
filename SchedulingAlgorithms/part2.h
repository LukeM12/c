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

#define ERROR_DEADLOCK 80
#define ERROR_DEADLOCK_out "ERROR: DEADLOCK"

#define ERROR_LOOP 82
#define ERROR_LOOP_out "ERROR: LOOPING INIFINITELY" 


#define ERROR_FILEIO 83
#define ERROR_FILEIO_out "ERROR: FILE CREATION FAVL"

#define ERROR_NOEXIT 84

#define ERROR_PCBCREATION 85
#define ERROR_PCBCREATION_out "ERROR: PCB CREATION FAIL"

#define MAX_ERROR 10
/* A mini process control block that holds the state of the process */
typedef struct {
    int pid;
    char *cpu_info;
    int remaining_time;
    struct miniPCB *next, *prev;
} miniPCB; 

typedef struct {
    miniPCB *start, *end;
} QueueList;

int index;
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
int testparseInputFile();
/**
 * Description: read the input file and return the File instance
 * @param: a string of the filename
 * return the file in stance
 */
FILE *readInputFile(char *);
int testReadInputFile(char*);

