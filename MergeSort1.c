#include<stdio.h>
#include<stdlib.h>

void display(int *arr, int size) {
    for(int i = 0; i < size; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

void merge(int *L, int L_size, int *R, int R_size, int *arr) {
    int i = 0, j = 0, k = 0;

    while(i < L_size && j < R_size) {
        if(L[i] < R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < L_size) {
        arr[k++] = L[i++];
    }

    while(j < R_size) {
        arr[k++] = R[j++];
    }
}

void mergeSort(int *arr, int n) {
    if(n > 1) {
        int mid = n/2;
        int *left = (int *) malloc(mid*sizeof(int));
        int *right = (int *) malloc((n-mid)*sizeof(int));


        for(int i = 0; i < mid; i++) left[i] = arr[i];
        for(int i = mid; i < n; i++) right[i-mid] = arr[i]; 

        mergeSort(left, mid);
        mergeSort(right, n-mid);
        merge(left, mid, right, n-mid, arr);

        free(left);
        free(right);
    }
}

int main() {
    int arr[] = {8, 2, 1, 4, 6, 7, 9, 3};
    display(arr, 8);
    mergeSort(arr, 8);
    display(arr, 8);
    return 0;
}