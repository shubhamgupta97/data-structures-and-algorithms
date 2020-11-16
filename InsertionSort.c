#include<stdio.h>
#include<stdlib.h>

void insertionSort(int *arr, int n) {
    int i, j, key;

    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key)
            arr[j+1] = arr[j--];

        arr[j+1] = key;
    }
}

void display(const char* msg, int *arr, int n) {
    int i;

    printf("%s:\t", msg);
    for(i = 0; i < n; i++) 
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
    insertionSort(arr, n);
    display("Sorted Array", arr, n);
    
    return 0;
}