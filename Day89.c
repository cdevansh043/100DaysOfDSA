#include <stdio.h>
#include <stdlib.h>

int isFeasible(int pages[], int n, int m, int max_pages) {
    int students_count = 1;
    int current_sum = 0;

    for (int i = 0; i < n; i++) {
        if (pages[i] > max_pages) return 0;

        if (current_sum + pages[i] > max_pages) {
            students_count++;
            current_sum = pages[i];
            if (students_count > m) return 0;
        } else {
            current_sum += pages[i];
        }
    }
    return 1;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    int *pages = (int *)malloc(n * sizeof(int));
    int sum = 0, max_val = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
        sum += pages[i];
        if (pages[i] > max_val) max_val = pages[i];
    }

    if (m > n) {
        printf("-1\n");
        free(pages);
        return 0;
    }

    int low = max_val, high = sum, ans = sum;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isFeasible(pages, n, m, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%d\n", ans);

    free(pages);
    return 0;
}