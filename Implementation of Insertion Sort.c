#include <stdio.h>

void insertion_sort(int a[], int size);

int main(void){
    int size, i;
    printf("Insertion Sort\n");
    
    //Prompting user for the size of the List
    printf("Enter Size of List: ");
    scanf("%d", &size);
    
    //Declaring a array of required size 
    int List[size];
    printf("Enter List Elements: \n");

    //Reading elements using for loop
    for(i = 0; i < size; i++){
        scanf("%d", &List[i]);
    }

    //Printing Unsorted List
    printf("Unsorted List: ");
    for(i = 0; i < size; i++){
        printf("%d ", List[i]);
    }
    //Sorting list using insertion_sort
    insertion_sort(List, size);

    //Printing Sorted List
    printf("\nSorted List: ");
    for(i = 0; i < size; i++){
        printf("%d ", List[i]);
    }
    printf("\n");

    return 0;
}

void insertion_sort(int a[], int size){
    int i, j;  //declaring a countervariable since in older c version it is a prerequisite to do this
    for(i = 1; i < size; i++){
        int temp = a[i];
        for(j = i; j > 0 && a[j - 1] > temp; j--)
            a[j] = a[j - 1];
        a[j] = temp;
    }
}
