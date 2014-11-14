#include "part2.h"

int testcreateminiProcess(int pid, char *type){
    miniPCB *pcbObject ;

    //Create a mini process and check its fields
    pcbObject= createminiProcess(2, type);
    if (pcbObject == NULL){
            //report errors in these lines
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

int testisReady(miniPCB pcb){
    return FALSE;
}


int testisRunning(miniPCB pcb){

    return FALSE;
}
int testIsWaiting(miniPCB pcb){
    return FALSE;

}
int testisTerminated(miniPCB pcb){
    return FALSE;
}
int  testgetTime(miniPCB pcb){
    return 0.0;
}
int testparseInputFile(){
  // FILE * inFile = readInputFile("input.config");
   // char *a;
   // a = parseInputFile(inFile);
    return NULL;
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

