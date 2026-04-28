#include <stdio.h>

struct Activity {
    int start, finish;
};

void sort(struct Activity arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j].finish > arr[j+1].finish) {
                struct Activity temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void activitySelection(struct Activity arr[], int n) {
    sort(arr, n);

    int i = 0;
    printf("Selected Activities:\n");
    printf("(%d, %d)\n", arr[i].start, arr[i].finish);

    for (int j = 1; j < n; j++) {
        if (arr[j].start >= arr[i].finish) {
            printf("(%d, %d)\n", arr[j].start, arr[j].finish);
            i = j;
        }
    }
}