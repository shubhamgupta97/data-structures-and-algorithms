#include<stdio.h>
#include<stdlib.h>
#define RANGE 10

int* countingSort(int *arr, int n, int range) {
    int i;
    int *count = (int*)calloc(range, sizeof(int));
    int *output = (int*)calloc(range, sizeof(int));

    for(i = 0; i < n; i++) 
        count[arr[i]]++;
    

    for(i = 1; i < range; i++) 
        count[i] += count[i-1];
    
    for(i = 0; i < n; i++) {
        output[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }

    return output;
}

void display(const char *msg, int *arr, int size) {
    int i;

    printf("%s:\t", msg);
    for(i = 0; i < size; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

int getInput(int **arr) {
    int n, i;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    *arr = (int*)calloc(n, sizeof(int));

    printf("Enter the elements of the array: ");
    for(i = 0; i < n; i++)
        scanf("%d", (*arr)+i);

    return n;
}

int main() {
    int n, *arr;
    n = getInput(&arr);

    display("Original Array", arr, n);
    arr = countingSort(arr, n, RANGE);
    display("Sorted Array", arr, n);

    return 0;
}