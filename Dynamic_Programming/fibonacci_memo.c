#include <stdio.h>

int dp[100];

int fib(int n) {
    if (n <= 1) return n;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = fib(n-1) + fib(n-2);
}

int main() {
    int n = 10;

    for (int i = 0; i <= n; i++)
        dp[i] = -1;

    printf("Fib(%d) = %d\n", n, fib(n));
}