#include <stdio.h>

void shellSort(int arr[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            for (int j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main() {
    int arr[] = {12, 34, 54, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Original array: \n");
    for(int i=0; i<n; i++) printf("%d ", arr[i]);

    shellSort(arr, n);

    printf("\nSorted array: \n");
    for(int i=0; i<n; i++) printf("%d ", arr[i]);

    return 0;
}
