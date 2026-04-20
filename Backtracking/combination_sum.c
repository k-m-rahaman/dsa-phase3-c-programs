#include <stdio.h>

void combination(int arr[], int n, int target, int index, int temp[], int size) {
    if (target == 0) {
        for (int i = 0; i < size; i++)
            printf("%d ", temp[i]);
        printf("\n");
        return;
    }

    for (int i = index; i < n; i++) {
        if (arr[i] <= target) {
            temp[size] = arr[i];
            combination(arr, n, target - arr[i], i, temp, size + 1);
        }
    }
}

int main() {
    int arr[] = {2, 3, 6, 7};
    int temp[10];

    combination(arr, 4, 7, 0, temp, 0);
    return 0;
}