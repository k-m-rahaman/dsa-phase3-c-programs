#include <stdio.h>
#include <limits.h>

int minCoins(int coins[], int m, int amount) {
    int dp[amount+1];

    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
        dp[i] = INT_MAX;

    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < m; j++) {
            if (coins[j] <= i) {
                int res = dp[i - coins[j]];
                if (res != INT_MAX && res + 1 < dp[i])
                    dp[i] = res + 1;
            }
        }
    }

    return dp[amount];
}