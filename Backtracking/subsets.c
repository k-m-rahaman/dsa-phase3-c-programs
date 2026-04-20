#include <stdio.h>

void generateSubsets(int arr[], int n, int index, int subset[], int size) {
    if (index == n) {
        printf("{ ");
        for (int i = 0; i < size; i++)
            printf("%d ", subset[i]);
        printf("}\n");
        return;
    }

    // Include element
    subset[size] = arr[index];
    generateSubsets(arr, n, index + 1, subset, size + 1);

    // Exclude element
    generateSubsets(arr, n, index + 1, subset, size);
}

int main() {
    int arr[] = {1, 2, 3};
    int subset[10];
    generateSubsets(arr, 3, 0, subset, 0);
    return 0;
}