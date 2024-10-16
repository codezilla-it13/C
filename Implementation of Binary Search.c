#include <stdio.h>

void Binary_search(int a[], int first, int last, int target);
void insertion_sort(int a[], int size);     //We can just give the data in a Ascending order instead of using insertion_sort here

int main(void){
    int size, target, i;
    printf("Binary Search\n");
    
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

    //Sorting list using insertion_sort
    insertion_sort(List, size);

    //Printing Sorted List
    printf("\nSorted List: ");
    for(i = 0; i < size; i++){
        printf("%d ", List[i]);
    }

    //Prompting user for target
    printf("Enter Element to Search: ");
    scanf("%d", &target);

    //Calling Binary_search to find the target
    Binary_search(List, 0, size-1, target);
    return 0;
}

void Binary_search(int a[], int first, int last, int target){
    int mid = (first+last)/2;

    while(first <= last){
        if(a[mid] > target){
            last = mid - 1;
        }else if(a[mid] < target){
            first = mid + 1;
        }else{
            printf("Target %d found at Position %d\n", target, (mid + 1));
            return;
        }
        mid = (first+last)/2;
    }

    printf("Target %d is not Found\n", target);
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
