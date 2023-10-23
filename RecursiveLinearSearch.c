#include <stdio.h>

int recursiveLinearSearch(int arr[], int start, int end, int target) {
    if (start > end) {
        return -1; // Base case: element not found
    }
    
    if (arr[start] == target) {
        return start; // Base case: element found at index start
    }
    
    return recursiveLinearSearch(arr, start + 1, end, target); // Recursive case
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 22;
    
    int index = recursiveLinearSearch(arr, 0, n - 1, target);
    
    if (index != -1) {
        printf("Element found at index %d\n", index);
    } else {
        printf("Element not found\n");
    }
    
    return 0;
}

