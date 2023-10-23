#include <stdio.h>

void OSS(int arr[], int n) {
    int i, j, temp, min_idx, swap_count = 0;
    int swapped;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
                
                swapped = 1;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
        if (min_idx != i) {
            swap_count++;
        }
        if (swapped == 0)
            break;
    }
    printf("Number of swaps required by Selection Sort: %d\n", swap_count);
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
	int i; 
	
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    OSS(arr, n);

    int j;
    printf("Sorted array:\n");
    for (j = 0; j < n; j++) {
        printf("%d ", arr[j]);
    }
    printf("\n");

    return 0;
}

