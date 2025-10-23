#include <stdio.h>
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int minindex = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minindex]) {
                minindex = j;
            }
        }
        int temp = arr[minindex];
        arr[minindex] = arr[i];
        arr[i] = temp;
    }
}
int main() {
    int arr[] = {29, 10, 14, 37};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    selectionSort(arr, n);
    printf("\nSorted array: \n");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
