#include<stdio.h>
#include<stdlib.h>

void display(const char *msg, int *arr, int size) {
    int i;
    
    printf("%s:\t", msg);
    for(i = 0; i < size; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

void merge(int *L, int L_size, int *R, int R_size, int *arr) {
    int i, j, k;

    i = 0, j = 0, k = 0;

    while(i < L_size && j < R_size) {
        if(L[i] < R[j])
            arr[k++] = L[i++];
        else 
            arr[k++] = R[j++];
    }

    while(i < L_size) 
        arr[k++] = L[i++];

    while(j < R_size)
        arr[k++] = R[j++];
}

void mergeSort(int *arr, int n) {
    int i, mid, *left, *right;
    if(n > 1) {
        mid = n/2;
        left = (int *) malloc(mid*sizeof(int));
        right = (int *) malloc((n-mid)*sizeof(int));


        for(i = 0; i < mid; i++) left[i] = arr[i];
        for(i = mid; i < n; i++) right[i-mid] = arr[i]; 

        mergeSort(left, mid);
        mergeSort(right, n-mid);
        merge(left, mid, right, n-mid, arr);

        free(left);
        free(right);
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
    mergeSort(arr, n);
    display("Sorted Array", arr, n);

    return 0;
}