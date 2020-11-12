#include<stdio.h>

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

void display(int *arr, int n) {
    for(int i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

int main () {
    int arr[] = {8,2,1,4,6,3,7,9};
    insertionSort(arr, 8);
    display(arr, 8);
    return 0;
}