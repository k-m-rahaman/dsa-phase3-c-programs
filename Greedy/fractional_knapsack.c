#include <stdio.h>

struct Item {
    int value, weight;
};

void sort(struct Item arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            float r1 = (float)arr[j].value / arr[j].weight;
            float r2 = (float)arr[j+1].value / arr[j+1].weight;

            if (r1 < r2) {
                struct Item temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

float knapsack(struct Item arr[], int n, int W) {
    sort(arr, n);
    float total = 0.0;

    for (int i = 0; i < n; i++) {
        if (W >= arr[i].weight) {
            total += arr[i].value;
            W -= arr[i].weight;
        } else {
            total += (float)arr[i].value * W / arr[i].weight;
            break;
        }
    }
    return total;
}