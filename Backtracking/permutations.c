#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permute(int arr[], int l, int r) {
    if (l == r) {
        for (int i = 0; i <= r; i++)
            printf("%d ", arr[i]);
        printf("\n");
        return;
    }

    for (int i = l; i <= r; i++) {
        swap(&arr[l], &arr[i]);
        permute(arr, l + 1, r);
        swap(&arr[l], &arr[i]); // backtrack
    }
}

int main() {
    int arr[] = {1, 2, 3};
    permute(arr, 0, 2);
    return 0;
}