#include <stdio.h>
#include <stdlib.h>

void merge(int left[], int leftLength, int right[], int rightLength, int result[]) {
    int ll = 0, rr = 0, resIdx = 0;
  
    while (ll < leftLength && rr < rightLength) {
        if (left[ll] < right[rr]) {
            result[resIdx++] = left[ll++];
        } else {
            result[resIdx++] = right[rr++];
        }
    }
  
    while (ll < leftLength) {
        result[resIdx++] = left[ll++];
    }
  
    while (rr < rightLength) {
        result[resIdx++] = right[rr++];
    }
}

void mergeSort(int arr[], int length) {
    if (length <= 1) {
        return;
    }
  
    int mid = length / 2;
  
    int left[mid];
    int right[length - mid];
  
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
  
    for (int i = mid; i < length; i++) {
        right[i - mid] = arr[i];
    }
  
    mergeSort(left, mid);
    mergeSort(right, length - mid);
  
    merge(left, mid, right, length - mid, arr);
}

void printArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {43, 23, 10, 7, 36, 87, 5, 19};
    int length = sizeof(arr) / sizeof(arr[0]);
  
    printf("Original array: ");
    printArray(arr, length);
  
    mergeSort(arr, length);
  
    printf("Sorted array: ");
    printArray(arr, length);
  
    return 0;
}