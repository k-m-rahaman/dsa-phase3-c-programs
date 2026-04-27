#include <stdio.h>

int max(int a, int b) { return (a > b) ? a : b; }

int lis(int arr[], int n) {
    int dp[n];
    int result = 1;

    for (int i = 0; i < n; i++)
        dp[i] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        result = max(result, dp[i]);
    }

    return result;
}