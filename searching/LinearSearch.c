#include <stdio.h>
// Returns the index of the target in the array if found, otherwise returns -1
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i;
    }
    
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40, 50, 70, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    
    int result = linearSearch(arr, n, target);
    
    if (result == -1)
        printf("Element %d is not present in array\n", target);
    else
        printf("Element %d is present at index %d\n", target, result);
    
    return 0;
}