#include<stdio.h>
#include<stdlib.h>

void display(const char *msg, int *arr, int size) {
    int i;
    
    printf("%s:\t", msg);
    for(i = 0; i < size; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

void merge(int arr[], int L, int M, int R) {
    // Loop variables
    int i, j, k;

    // Size of the two partitions
    int n1 = M-L+1,
        n2 = R-M;

    // Two arrays to store the left and right partitions
    int left[n1], right[n2];

    // Populating the halves
    for(i = L; i <= M; i++) left[i-L] = arr[i];
    for(i = M+1; i <= R; i++) right[i-M-1] = arr[i];

    i = 0, j = 0, k = L;

    while(i < n1 && j < n2) {
        if(left[i] < right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    while(i < n1)   arr[k++] = left[i++];

    while(j < n2)   arr[k++] = right[j++];
}

void mergeSort(int arr[], int L, int R) {
    if(L < R) {
        int M = L + (R-L)/2;

        mergeSort(arr, L, M);
        mergeSort(arr, M+1, R);
        merge(arr, L, M, R);
    }
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
    mergeSort(arr, 0, n-1);
    display("Sorted Array", arr, n);

    return 0;
}