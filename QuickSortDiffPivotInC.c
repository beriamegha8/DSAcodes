#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int choosePivot(int arr[], int low, int high, int pivotChoice) {
    if (pivotChoice == 1) 
        return (low + high) / 2;
    else if (pivotChoice == 2) 
        return low;
    else 
        return high;
}

int partition(int arr[], int low, int high, int pivotChoice) {
    int pivotIndex = choosePivot(arr, low, high, pivotChoice);
    int pivotValue = arr[pivotIndex];
    swap(&arr[pivotIndex], &arr[high]);

    int i = low - 1;
    int j;

    for (j = low; j < high; j++) {
        if (arr[j] < pivotValue) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high, int pivotChoice) {
    if (low < high) {
        int pivot = partition(arr, low, high, pivotChoice);
        quickSort(arr, low, pivot - 1, pivotChoice);
        quickSort(arr, pivot + 1, high, pivotChoice);
    }
}

int i;
void displayArray(int arr[], int n) {
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, choice;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    int k;

    printf("Enter %d elements:\n", n);
    for (k = 0; k < n; k++) {
        scanf("%d", &arr[k]);
    }

    printf("Original array: ");
    displayArray(arr, n);

    printf("\nChoose the pivot:\n");
    printf("1. Middle Element\n");
    printf("2. First Element\n");
    printf("3. Last Element\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    quickSort(arr, 0, n - 1, choice);

    printf("Sorted array: ");
    displayArray(arr, n);

    return 0;
}

