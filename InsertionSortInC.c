#include <stdio.h>

// Function to perform insertion sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;

    // Get the number of elements from the user
    printf("Enter the number of elements: ");
    scanf("%d", &n);
	int i;
    int arr[n];

    // Input the elements from the user
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Call the insertion sort function
    insertionSort(arr, n);

    // Display the sorted array
    int j;
    printf("Sorted array:\n");
    for (j = 0; j < n; j++) {
        printf("%d ", arr[j]);
    }
    printf("\n");

    return 0;
}

