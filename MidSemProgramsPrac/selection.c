#include <stdio.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min_idx = i; // Assume current i is the minimum
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j; // Update min_idx if a smaller element is found
            }
        }
        // Swap the found minimum element with the first element
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int arr[] = {29, 10, 14, 37, 14};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    for(int i=0; i<n; i++) printf("%d ", arr[i]);

    selectionSort(arr, n);

    printf("\nSorted array: \n");
    for(int i=0; i<n; i++) printf("%d ", arr[i]);

    return 0;
}
