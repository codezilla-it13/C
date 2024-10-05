#include <stdio.h>
#define MAX 6

void enqueue(int element);
int dequeue();
void display();

int queue[MAX];
int front = -1;
int rear = -1;

int main(){
	int choice =1, x;
	
	printf("\n1: Insert");
	printf("\n2: Delete");
	printf("\n3. Display");
		
	while(choice < 4 && choice != 0){
		printf("\nEnter your Choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1: 
				printf("Enter the element to be inserted: ");
				scanf("%d", &x);
				enqueue(x);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			default:
				printf("\nInvalid  Choice\nExiting...");
		}
	}
	return 0;
}

void enqueue(int element){
	if(front == -1 && rear == -1){
		front = 0;
		rear = 0;
		queue[rear] = element;
	}else if((rear + 1)%MAX == front)
		printf("Queue is overflow\n");
	else{
		rear = (rear+1) % MAX;
		queue[rear] = element;
	}
}

int dequeue(){
	if((front == -1) && (rear == -1)){
		printf("\nQueue is Underflow");
	}else if(front == rear){
		printf("\nThe dequeued Element is %d", queue[front]);
		front = -1;
		rear = -1;
	}else{
		printf("\nThe dequeued element is %d", queue[front]);
		front = (front + 1)%MAX;
	}
}

void display(){
	int i = front;
	if(front == -1 && rear == -1)
		printf("\nQueue is empty");
	else{
		printf("\nElements in a Queue are \n");
		while(i <= rear){
			printf("%d\n", queue[i]);
			i = (i +1)%MAX;
		}
	}
}
