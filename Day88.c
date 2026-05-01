#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int canPlaceCows(int positions[], int n, int k, int minDist) {
    int count = 1;
    int lastPos = positions[0];
    for (int i = 1; i < n; i++) {
        if (positions[i] - lastPos >= minDist) {
            count++;
            lastPos = positions[i];
            if (count >= k) return 1;
        }
    }
    return 0;
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;

    int *positions = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &positions[i]);
    }

    qsort(positions, n, sizeof(int), compare);

    int low = 1, high = positions[n - 1] - positions[0], ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canPlaceCows(positions, n, k, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("%d\n", ans);

    free(positions);
    return 0;
}