#include <stdio.h>
#include <stdlib.h>

int isPossible(int boards[], int n, int k, long long max_time) {
    int painters_count = 1;
    long long current_time = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > max_time) return 0;

        if (current_time + boards[i] > max_time) {
            painters_count++;
            current_time = boards[i];
            if (painters_count > k) return 0;
        } else {
            current_time += boards[i];
        }
    }
    return 1;
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;

    int *boards = (int *)malloc(n * sizeof(int));
    long long sum = 0;
    int max_val = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
        sum += boards[i];
        if (boards[i] > max_val) max_val = boards[i];
    }

    long long low = max_val, high = sum, ans = sum;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (isPossible(boards, n, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%lld\n", ans);

    free(boards);
    return 0;
}