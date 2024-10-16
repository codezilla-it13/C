#include <stdio.h>

void Selection_sort(int a[], int size);

int main(void){
    int size, i;
    printf("Selection Sort\n");
    
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
    //Sorting list using Selection_sort
    Selection_sort(List, size);

    //Printing Sorted List
    printf("\nSorted List: ");
    for(i = 0; i < size; i++){
        printf("%d ", List[i]);
    }
    printf("\n");

    return 0;
}

void Selection_sort(int a[], int size){
    int i, j;  //declaring a countervariable since in older c version it is a prerequisite to do this
    for(i = 0; i < size - 1; i++){
        int min = i;
        for(j = i+1; j < size; j++)
            if(a[j] < a[min])  
                min = j;
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}
