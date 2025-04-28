#include <stdio.h>
// Returns the index of the target in the array if found, otherwise returns -1
int binarySearchRecursive(int arr[], int left, int right, int target) {
    // Base case: element not found
    if (left > right)
        return -1;
    
    // Calculate middle point with simple division
    int mid = (left + right) / 2;
    
    // If the element is present at the middle
    if (arr[mid] == target)
        return mid;
    
    // If element is smaller than mid, search in the left subarray
    if (arr[mid] > target)
        return binarySearchRecursive(arr, left, mid - 1, target);
    
    // Else search in the right subarray
    return binarySearchRecursive(arr, mid + 1, right, target);
}

int main() {
    int arr[] = {2, 3, 4, 10, 40, 50, 70, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    
    int result = binarySearchRecursive(arr, 0, n-1, target);
    
    if (result == -1)
        printf("Element %d is not present in array\n", target);
    else
        printf("Element %d is present at index %d\n", target, result);
    
    return 0;
}