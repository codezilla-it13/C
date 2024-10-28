#include <stdio.h>

int tsize;

int hasht(int key){
    int i = key % tsize;
    return i;
}

//QUADRATIC PROBING
int rehashq(int key, int j){
    int i = (key+(j*j)) % tsize;
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
        j = 1;
        key = arr[k];
        i = hasht(key);
        while(hash[i] != -1){
            i = rehashq(i, j);
            j++;
        }
        hash[i] = key;
    }
    printf("\nThe elements in the array are: ");
    for(i = 0; i < tsize; i++)
        printf("\nElement at position %d: %d", i, hash[i]);
    return 0;
}