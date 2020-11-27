#include<stdio.h>
#include<stdlib.h>

void display(const char *msg, int *arr, int size) {
    int i;
    
    printf("%s:\t", msg);
    for(i = 0; i < size; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

void cocktailSort(int *arr, int n) {
    int i, temp, isSwapped, start, end, noOfForwardPasses, noOfBackwardPasses;

    noOfForwardPasses = 0;
    noOfBackwardPasses = 0;
    
    isSwapped = 1;
    start = 0;
    end = n-1;

    while(isSwapped) {
        isSwapped = 0;

        for(i = start; i < end; i++) {
            if(arr[i] > arr[i+1]) {
                isSwapped = 1;
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
        noOfForwardPasses++;

        if(!isSwapped)
            break;

        isSwapped = 0;
        end--;

        for(i = end-1; i >= start; i--) {
            if(arr[i] > arr[i+1]) {
                isSwapped = 1;
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
        noOfBackwardPasses++;
        start++;
    }

    display("Sorted Array" ,arr, 8);
    printf("Number of forward passes: %d\nNumber of backward passes: %d\n", noOfForwardPasses, noOfBackwardPasses);
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
    cocktailSort(arr, n);
    
    return 0;
}