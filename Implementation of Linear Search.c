#include <stdio.h>

void linear_search(int a[], int size, int target);

int main(void){
    int size, target, i;
    printf("Linear Search\n");
    
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

    //Prompting user for target
    printf("Enter Element to Search: ");
    scanf("%d", &target);

    //Calling linear_search to find the target
    linear_search(List, size, target);
    return 0;
}

void linear_search(int a[], int size, int target){
    int i;  //declaring a countervariable since in older c version it is a prerequisite to do this
    for(i = 0; i < size; i++){
        if(a[i] == target){     
            printf("Target %d found at Position %d\n", target, (i + 1));
            return;
        }
    }
    printf("Target %d is not Found\n", target);
}
