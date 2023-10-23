#include <stdio.h>

void bubble_sort(int arr[], int n) {
    int i, j, temp, swap_count = 0;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swap_count++;
            }
        }
    }
    printf("Number of swaps required by Bubble Sort: %d\n", swap_count);
}

void selection_sort(int arr[], int n) {
    int i, j, temp, min_idx, swap_count = 0;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
        if (min_idx != i) {
            swap_count++;
        }
    }
    printf("Number of swaps required by Selection Sort: %d\n", swap_count);
}

int main() {
    int n, i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    bubble_sort(arr, n);
    selection_sort(arr, n);
    printf("Sorted array in ascending order:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

