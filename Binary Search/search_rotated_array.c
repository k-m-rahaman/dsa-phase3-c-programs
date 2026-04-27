#include <stdio.h>

int search(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[left] <= arr[mid]) {
            if (target >= arr[left] && target < arr[mid])
                right = mid - 1;
            else
                left = mid + 1;
        } else {
            if (target > arr[mid] && target <= arr[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return -1;
}