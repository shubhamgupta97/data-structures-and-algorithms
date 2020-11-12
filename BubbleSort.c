#include<stdio.h>

void bubbleSort(int *arr, int n) {
    int i, j, temp, isSwapped, noOfPasses = 0;

    for(i = 0; i < n; i++) {
        noOfPasses++;
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

    printf("Number of passes: %d\n", noOfPasses);
}

void display(int *arr, int n) {
    int i;

    for(i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
    
}

int main() {
    int arr[] = {8, 2, 1, 4, 6, 7, 9, 3};
    display(arr, 8);
    bubbleSort(arr, 8);
    display(arr, 8);
    return 0;
}