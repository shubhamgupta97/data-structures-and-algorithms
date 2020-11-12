#include<stdio.h>

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

    printf("Number of forward passes: %d\nNumber of backward passes: %d\n", noOfForwardPasses, noOfBackwardPasses);
}

void display(int *arr, int n) {
    int i;

    for(i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
    
}

int main() {
    int arr[] = {8, 2, 1, 4, 6, 7, 9, 3};
    // int arr[] = {1, 2, 3, 4, 6, 7, 9, 8};
    display(arr, 8);
    cocktailSort(arr, 8);
    display(arr, 8);
    return 0;
}