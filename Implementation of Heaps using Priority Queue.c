#include <stdio.h>
#include <math.h>
 
#define MAX 100

void swap(int*, int*);
void display(int[], int);
void insert(int[], int, int, int);
int del_hi_priori(int[], int, int);

int main(){
    int choice, num, n, a[MAX], data, s;

    int lb = 0;
    n = 0;

    printf(".....MAIN MENU.....\n");
    printf("\n1. Insert\n");
    printf("\n2. Delete\n");
    printf("\n3. Display\n");
    printf("\n4. Quit\n");

    while(1){
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter Data to be Inserted: ");
                scanf("%d", &data);
                insert(a, n, data, lb);
                n++;
                break;
            case 2:
                s = del_hi_priori(a, n+1, lb);
                if(s != 0)
                    printf("\nThe Deleted Value is: %d\n", s);
                if(n > 0)
                    n--;
                break;
            case 3:
                printf("\n");
                display(a, n);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid Choice\n");
        }
        printf("\n\n");
    }
    return 0;
}

void insert(int a[], int heapsize, int data, int lb){
    int i, p;
    int parent(int);
    if(heapsize == MAX){
        printf("Queue is Full!\n");
        return;
    }
    i = lb + heapsize;
    a[i] = data;

    while(i > lb && a[p = parent(i)] < a[i]){
        swap(&a[p], &a[i]);
        i = p;
    }
}

int del_hi_priori(int a[], int heapsize, int lb){
    int data, i, l, r, max_child, t;
    int left(int);
    int right(int);

    if(heapsize == 1){
        printf("Queue is Empty!!\n");
        return 0;
    }
    t = a[lb];
    swap(&a[lb], &a[heapsize - 1]);
    i = lb;
    heapsize--;

    while(1){
        l = left(i);        //
        if(l >= heapsize)
            break;
        if((r = right(i)) >= heapsize)
            max_child = l;
        else
            max_child = (a[l] > a[r])?1:r;
        if(a[i] >= a[max_child])
            break;
        swap(&a[i], &a[max_child]);
        i = max_child;
    }
    return t;
}

int parent(int i){
    return (i - 1) / 2;
}

int left(int i){
    return 2*i+1;
}

int right(int i){
    return 2*i+2;
}

void display(int a[], int n){
    int i;
    if(n == 0){
        printf("Queue is Empty!!\n");
        return;
    }
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void swap(int *p, int *q){
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}