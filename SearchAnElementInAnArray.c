#include <stdio.h>
#include <stdlib.h>

#define max 100 // Maximum array size

void sortArray(int arr[], int size);
int LinearSearch(int arr[], int size, int search);
int IterativeBinarySearch(int arr[], int l, int r, int search);

int main() {
    system("CLS");
    int choice, i;
    int arr[max];
    int size, toSearch, found;

    printf("Enter size of the array: ");
    scanf("%d", &size);

    printf("Enter elements in the array: ");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    sortArray(arr, size);

    printf("\nEnter element to search: ");
    scanf("%d", &toSearch);
    printf("Press 1 for Linear Search and 2 for Binary Search: ");
    scanf("%d", &choice);

    if (choice == 1) {
        LinearSearch(arr, size, toSearch);
    } 
	else if (choice == 2) {
        int result = IterativeBinarySearch(arr, 0, size - 1, toSearch);
        if (result == -1) {
            printf("Element is not present in the array\n");
        } 
		else {
            printf("Element is present at position %d\n", result);
        }
    }

    return 0;
}

void sortArray(int arr[], int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int LinearSearch(int arr[], int size, int search) {
    int i;
    int found = 0;

    for (i = 0; i < size; i++) {
        if (arr[i] == search) {
            found++;
            printf("%d is found at position %d\n", search, i + 1);
        }
    }

    if (found == 0) {
        printf("%d is not found in the array\n", search);
    } else if (found > 0) {
        printf("Number of occurrences of %d is %d\n", search, found);
    }

    return 0;
}

int IterativeBinarySearch(int arr[], int l, int r, int search) {
    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == search) {
            return mid;
        }

        if (arr[mid] < search) {
            l = mid + 1;
        } 
		else {
            r = mid - 1;
        }
    }

    return -1;
}


