#include <stdio.h>

int tsize;

int hasht(int key){
    int i = key % tsize;
    return i;
}

//LINEAR PROBING
int rehashl(int key){
    int i;
    i = (key+1) % tsize;
    return i;
}

int main(void){
    int key, arr[20], hash[20], i, n, s, op, j, k;

    printf("Enter the size of the hash table: ");
    scanf("%d", &tsize);
    printf("\nEnter the no of Elements: ");
    scanf("%d", &n);
    for(i = 0; i < tsize; i++)
        hash[i] = -1;
    printf("Enter Elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for(i = 0; i < tsize; i++)
        hash[i] = -1;
    for(k = 0; k < n; k++){
        key = arr[k];
        i = hasht(key);
        while(hash[i] != -1)
            i = rehashl(i);
        hash[i] = key;
    }
    printf("\nThe elements in the array are: ");
    for(i = 0; i < tsize; i++)
        printf("\nElement at position %d: %d", i, hash[i]);
    return 0;
}