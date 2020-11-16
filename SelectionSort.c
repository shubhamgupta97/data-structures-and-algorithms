#include<stdio.h>
#include<stdlib.h>

void selectionSort(int *arr, int n) {
    int i, j, min, temp;

    for(i = 0; i < n-1; i++) {
        min = i;
        for(j = i+1; j < n; j++) {
            if(arr[j] < arr[min])
                min = j;
        }

        if(min != i) {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
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
    
    display("Original Array", arr, 8);
    selectionSort(arr, 8);
    display("Sorted Array", arr, 8);
    
    return 0;
}