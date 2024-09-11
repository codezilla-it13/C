#include <stdio.h>
#include <stdlib.h>
struct node{
	int info;
	struct node *ptr;
}*front, *rear, *temp, *front1;
int frontelement();
void enq(int);
void deq();
void empty();
void display();
void create();
void queuesize();
int count = 0;
int main(){
	int no, ch, e;
	printf("1. Enqueue");
	printf("\n2. Dequeue");
	printf("\n3. Front Element");
	printf("\n4. Empty");
	printf("\n5. Exit");
	printf("\n6. Display");
	printf("\n7. Queue size\n");
	create();
	while(1){
		printf("\nEnter choice: ");
		scanf("%d", &ch);
		switch(ch){
			case 1:
				printf("Enter data: ");
				scanf("%d", &no);
				enq(no);
				break;
			case 2:
				deq();
				printf("\n");
				break;
			case 3:
				e = frontelement();
				if(e != 0)
					printf("Front Element: %d\n", e);
				else 
					printf("No Front Element, Queue is empty");
				break;
			case 4:
				empty();
				printf("\n");
				break;
			case 5:
				exit(0);
			case 6:
				display();
				printf("\n");
				break;
			case 7:
				queuesize();
				break;
			default:
				printf("Wrong choice, Enter Valid one");
		}
	}
}
void create(){
	front = rear = NULL;}
void queuesize(){
	printf("Queue size: %d\n", count);}
void enq(int data){
	if(rear == NULL){
		rear = (struct node*)malloc(sizeof(struct node));
		rear->ptr = NULL;
		rear->info = data;
		front = rear;
	}else{
		temp = (struct node*)malloc(sizeof(struct node));
		rear->ptr =temp;
		temp->info = data;
		temp->ptr = NULL;
		rear = temp;}
	count++;	
}
void display(){
	front1 = front;
	if((front1 == NULL) && (rear == NULL)){
		printf("Queue is empty\n");
		return;}
	while(front1 != rear){
		printf("%d ", front1->info);
		front1 = front1->ptr;}
	if(front1 == rear)
		printf("%d ", front1->info);
}
void deq(){
	front1 = front;
	if(front1 == NULL){
		printf("Error: Trying to display elements from Empty queue");
		return;
	}else if(front1->ptr != NULL){
		front1 = front1->ptr;
		printf("Dequeued value: %d", front->info);
		free(front);
		front = front1;
	}else{
		printf("Dequeued value: %d", front->info);
		free(front);
		front = NULL;
		rear = NULL;}
	count--;		
}
int frontelement(){
	if((front != NULL) && (rear != NULL))
		return(front->info);
	else
		return 0;
}
void empty(){
	if((front == NULL) && (rear == NULL))
		printf("Queue empty");
	else
		printf("Queue is not empty");
}
