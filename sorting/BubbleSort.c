#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int *arr, int n) {
    int i, j, temp, isSwapped;

    for(i = 0; i < n; i++) {
        isSwapped = 0;

        for(j = 0; j < n-1-i; j++) {
            if(arr[j] > arr[j+1]) {
                isSwapped = 1;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }

        if(isSwapped == 0)
            break;
    }
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
    bubbleSort(arr, n);
    display("Sorted Array", arr, n);

    return 0;
}