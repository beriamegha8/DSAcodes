#include <stdio.h>

void optimizedBubbleSort(int arr[], int n) {
    int i, j;
    int swapped; 

    for (i = 0; i < n - 1; i++) {
        swapped = 0; 

        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = 1; 
            }
        }

        if (swapped == 0)
            break;
    }
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

    optimizedBubbleSort(arr, n);

    int j;
    printf("Sorted array:\n");
    for (j = 0; j < n; j++) {
        printf("%d ", arr[j]);
    }
    printf("\n");

    return 0;
}

