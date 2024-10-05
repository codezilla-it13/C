#include <stdio.h>
#include <math.h>

#define MAX 100

void swap(int*, int*);
void display(int[], int);
void insert(int[], int*, int);
int del_hi_priori(int[], int*);

int main() {
    int choice, data;
    int heap[MAX];
    int n = 0; // current size of the heap

    printf(".....MAIN MENU.....\n");
    printf("\n1. Insert\n");
    printf("2. Delete\n");
    printf("3. Display\n");
    printf("4. Quit\n");

    while (1) {
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter Data to be Inserted: ");
                scanf("%d", &data);
                insert(heap, &n, data);
                break;
            case 2:
                data = del_hi_priori(heap, &n);
                if (data != -1)
                    printf("\nThe Deleted Value is: %d\n", data);
                break;
            case 3:
                printf("\n");
                display(heap, n);
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

void insert(int a[], int* heapsize, int data) {
    if (*heapsize == MAX) {
        printf("Queue is Full!\n");
        return;
    }

    int i = (*heapsize)++;
    a[i] = data;

    while (i != 0 && a[(i - 1) / 2] < a[i]) {
        swap(&a[i], &a[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int del_hi_priori(int a[], int* heapsize) {
    if (*heapsize == 0) {
        printf("Queue is Empty!!\n");
        return -1; // Return -1 to indicate an empty heap
    }

    int root = a[0];
    a[0] = a[--(*heapsize)]; // Move the last element to the root
    int i = 0;

    while (1) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int max_child = i;

        if (l < *heapsize && a[l] > a[max_child])
            max_child = l;
        if (r < *heapsize && a[r] > a[max_child])
            max_child = r;
        if (max_child == i)
            break;

        swap(&a[i], &a[max_child]);
        i = max_child;
    }

    return root;
}

void display(int a[], int n) {
    if (n == 0) {
        printf("Queue is Empty!!\n");
        return;
    }
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void swap(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}
