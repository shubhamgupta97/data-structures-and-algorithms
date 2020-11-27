#include<stdio.h>
#include<stdlib.h>

// Funtion to take user input
int getInput(int **arr) {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array: ");
    for(int i = 0; i < size; i++)
        scanf("%d", (*arr)+i);

    return size;
}

// Function to display the array elements
void display(const char *msg, int arr[], int size) {
    printf("%s:\t", msg);

    for(int i = 0; i < size; i++) 
        printf("%d ", arr[i]);

    printf("\n");
}

// Function to swap two numbers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to create partition
int partition(int arr[], int low, int high) {
    int pivot = arr[low], i = low, j = high, temp;
    while(i <= j) {
        // to find element greater than the pivot
        do {
            i++;
        } while(arr[i] <= pivot);

        // to find element lesser than the pivot
        do {
            j--;
        } while(arr[j] > pivot);

        // swapping numbers on either side of the pivot
        if(i <= j)
            swap(&arr[i], &arr[j]);
        
    }

    // placing the pivot element into its correct position
    swap(&arr[low], &arr[j]);

    // return pivot index
    return j;
}

void quickSort(int arr[], int low, int high) {
    if(low >= high)
        return;

    // find pivot
    int j = partition(arr, low, high);

    // sort left side of pivot
    quickSort(arr, low, j);

    // sort right side of pivot
    quickSort(arr, j+1, high);
}


int main()
{
    int *arr, n;
    n = getInput(&arr);

    display("Original Array", arr, n);
    quickSort(arr, 0, n);
    display("Sorted Array", arr, n);

    return 0;
}
