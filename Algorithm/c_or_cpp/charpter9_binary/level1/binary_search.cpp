#include <stdio.h>

int binarySearch2(int array[], int low, int high, int target) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (array[mid] == target) {
            return mid;
        } else if (array[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int binarySearch(int array[], int low, int high, int target) {
  if (low <= high) {
  		int mid = low + ((high - low) >> 1);
      if (array[mid] == target) {
      	return mid;
      } else if (array[mid] > target) {
     		 return binarySearch(array, low, mid - 1, target);
      } else {
      	return binarySearch(array, mid + 1, high, target);
      }
  }
  return -1;
}

int main() {
    int array[] = {1, 3, 5, 7, 9};
    int target = 5;
    int low = 0, high = 4;
    int index = binarySearch(array, low, high, target);
    if (index == -1) {
        printf("Target not found in the array.\n");
    } else {
        printf("Target found at index %d.\n", index);
    }
    return 0;
}