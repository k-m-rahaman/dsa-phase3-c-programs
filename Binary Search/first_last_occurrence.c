#include <stdio.h>

int firstOccurrence(int arr[], int n, int x) {
    int left = 0, right = n - 1, res = -1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == x) {
            res = mid;
            right = mid - 1;
        } else if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return res;
}

int lastOccurrence(int arr[], int n, int x) {
    int left = 0, right = n - 1, res = -1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == x) {
            res = mid;
            left = mid + 1;
        } else if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return res;
}