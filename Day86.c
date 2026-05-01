#include <stdio.h>

long long integerSquareRoot(long long n) {
    if (n < 2) return n;

    long long low = 0, high = n, ans = 0;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (mid <= n / mid) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    long long n;
    if (scanf("%lld", &n) != 1) return 0;

    printf("%lld\n", integerSquareRoot(n));

    return 0;
}