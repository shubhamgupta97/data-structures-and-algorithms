#include<stdio.h>
#include<stdlib.h>

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

int main() {
    int array[] = {3, 4, 2, 1, 3, 1};
    int *arr = array;

    display("Original Array", arr, 6);
    arr = countingSort(arr, 6, 10);
    display("Sorted Array", arr, 6);
    return 0;
}