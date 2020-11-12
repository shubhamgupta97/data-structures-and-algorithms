#include<stdio.h>
#include<stdlib.h>

void display(int *arr, int size) {
    for(int i = 0; i < size; i++)
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

int main() {
    int arr[] = {8, 2, 1, 4, 6, 7, 9, 3};

    display(arr, 8);
    mergeSort(arr, 0, 7);
    display(arr, 8);
    return 0;
}