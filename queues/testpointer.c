#include<stdio.h>
void add(int *);
int main(void){
        int a = 6;
      
        add( &a);
        printf("%i\n", a);
        return ;
}
void add(int *a){
    *a = 5;
}


