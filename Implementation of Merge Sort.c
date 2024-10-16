#include <stdio.h>

int Merge_sort(int start, int end, int a[], int aux[]);

int main(void){
    int size, i;
    printf("Merge Sort\n");
    
    //Prompting user for the size of the List
    printf("Enter Size of List: ");
    scanf("%d", &size);
    
    //Declaring a array of required size 
    int List[size],aux[size];
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
    Merge_sort(0, size-1, List, aux);

    //Printing Sorted List
    printf("\nSorted List: ");
    for(i = 0; i < size; i++){
        printf("%d ", List[i]);
    }
    printf("\n");

    return 0;
}
int Merge_sort(int start, int end, int a[], int aux[]){
    if(end <= start)
        return 0;
    
    int mid = (start + end)/2;

    Merge_sort(start, mid, a, aux);
    Merge_sort(mid+1, end, a, aux);

    int pointer_left = start;
    int pointer_right = mid + 1;
    int k;
    for(k = start; k <= end; k++){
        if(pointer_left == mid+1){
            aux[k] = a[pointer_right];
            pointer_right++;
        }else if(pointer_right == end+1){
            aux[k] = a[pointer_left];
            pointer_left++;
        }else if(a[pointer_left] < a[pointer_right]){
            aux[k] = a[pointer_left];
            pointer_left++;
        }else{
            aux[k] = a[pointer_right];
            pointer_right++;
        }
    }
    for(k = start; k <= end; k++){
        a[k] = aux[k];
    }
}