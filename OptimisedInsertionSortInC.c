#include <stdio.h>

// Binary search to find the insertion point
int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

// Optimized Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Find the insertion point using binary search
        int insertIndex = binarySearch(arr, 0, j, key);

        // Move elements to make space for the key
        while (j >= insertIndex) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Insert the key into the correct position
        arr[j + 1] = key;
    }
}

int main() {
    int n, i;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, n);

    printf("Sorted array in ascending order: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

