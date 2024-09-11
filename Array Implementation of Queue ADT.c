#include <stdio.h>
#define MAX 50
int queue_array[MAX];
int rear = -1, front = -1;
int main(){
	int choice;
	printf("1. Insert Element to Queue\n");
	printf("2. Delete Element from Queue\n");
	printf("3. Display all Elements of Queue\n");
	printf("4. Quit\n");
	while(1){
		printf("Enter Your Choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				insert();
				break;
			case 2:
				delet();
				break;
			case 3: 
				display();
				break;
			case 4:
				exit(1);
			default:
				printf("Wrong Choice!\n");
		}
	}
}
insert(){
	int add_item;
	if(rear == MAX-1)
		printf("Queue Overflow\n");
	else{
		if(front == -1)
			front = 0;
		printf("Insert the element in queue: ");
		scanf("%d", &add_item);
		rear++;
		queue_array[rear] = add_item;
	}
}
delet(){
	if(front == -1 || front > rear){
		printf("Queue Underflow\n");
		return;
	}else{
		printf("Element deleted from queue is: %d\n", queue_array[front]);
		front++;
	}
}
display(){
	int i;
	if(front == -1)
		printf("Queue is empty\n");
	else{
		printf("Queue is: ");
		for(i = front; i<= rear; i++)
			printf("%d ",queue_array[i]);
		printf("\n");
	}
}
