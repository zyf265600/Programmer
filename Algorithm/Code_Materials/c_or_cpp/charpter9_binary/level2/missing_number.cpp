#include <stdio.h>

 
int missingNumber(int* a, int length) {
  int left = 0;
  int right = length - 1;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (a[mid] == mid) {
    		left = mid + 1;
    } else {
   		 right = mid - 1;
    }
  }
  return left;
}

int main()
{
    int array[] = {0,1, 2, 3, 5,6,7};
    int index = missingNumber(array, 7);
    if (index == -1)
    {
        printf("Target not found in the array.\n");
    }
    else
    {
        printf("Target found at index %d.\n", index);
    }
    return 0;
}