#include<stdio.h>
#include<stdlib.h>
//Holding function for our linked list 
struct node{
	int a;
	struct node *next;
	struct node *prev;
};
	
struct node *head;

//This function returns a plain node
struct node *makenode(int val){
	struct node *temp = (struct node*)malloc(sizeof(struct node)); 
	temp->a =val;
	return temp;
}
//This function inserts a node at the front of the list 
static void insert_front(void){
	struct node *temp;
	//temp = makenode();
	if (!head){
		head = temp;
		return;
	}
	temp->next = head;
	head = temp;
}
//This node will traverse the list 
static void traverse(void){
	struct node *curr = head;
	while(curr){
		printf("the memory is %p\n", curr);
		curr = curr->next;
	}	
}
int main (int argc, char *args[]){
	//printf("%s\n", args[0]);
	struct node *list1;
	int *val;
	sscanf(args[1], "%d", &val);
	printf(" The value is  %d", val);
	//list1 = makenode(val); 
	return 0;
}





























