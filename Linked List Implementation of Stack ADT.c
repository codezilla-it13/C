#include <stdio.h>
#include <stdlib.h>
struct Node{
	int Data;
	struct Node *next;
}*top;
int push(int);		//declaration before hand reduces the conflicting types [Warning]
void popStack();
void display();
int main(){
	int i = 0;
	top = NULL;
	printf("1. Push to Stack");
	printf("\n2. Pop from Stack");
	printf("\n3. Display data of Stack");
	printf("\n4. Exit");
	while(1){
		printf("\nChoose Option: ");
		scanf("%d", &i);
		switch(i){
			case 1:{
				int value;
				printf("\nEnter a value to push into Stack: ");
				scanf("%d", &value);
				push(value);
				break;}
			case 2:
				popStack();
				printf("\nThe element is popped\n");
				break;
			case 3:
				display();
				break;
			case 4:{
					struct Node *temp;
					while(top != NULL){
						temp = top->next;
						free(top);
						top = temp;}
					exit(0);}
			default:
				printf("\nWrong Choice!");
		}
	}
}
int push(int value){		//Since it takes some value as a parameter I made it int and put return with no arguments
	struct Node *temp;
	temp = (struct Node *)malloc(sizeof(struct Node));
	temp->Data = value;
	if(top == NULL){
		top = temp;
		top->next = NULL;
	}else{
		temp->next = top;
		top = temp;
	}
	return;
}
void popStack(){
	struct Node *temp, *var = top;
	if(var == top){
		top = top->next;
		free(var);
	}else
		printf("\nStack Empty\n");
}
void display(){
	struct Node *var = top;
	if(var != NULL){
		printf("\nElements are as:");
		while(var != NULL){
			printf("\t%d", var->Data);
			var = var->next;
		}
		printf("\n");
	}else
		printf("\nStack is Empty\n");
}
