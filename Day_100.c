#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int original_idx;
} Element;

void mergeAndCount(Element arr[], int l, int m, int r, int count[]) {
    int n1 = m - l + 1;
    int n2 = r - m;

    Element *L = (Element *)malloc(n1 * sizeof(Element));
    Element *R = (Element *)malloc(n2 * sizeof(Element));

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    int right_less_count = 0;

    while (i < n1 && j < n2) {
        if (L[i].value <= R[j].value) {
            count[L[i].original_idx] += right_less_count;
            arr[k++] = L[i++];
        } else {
            right_less_count++;
            arr[k++] = R[j++];
        }
    }

    // Process remaining elements
    while (i < n1) {
        count[L[i].original_idx] += right_less_count;
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }

    free(L);
    free(R);
}

void solve(Element arr[], int l, int r, int count[]) {
    if (l < r) {
        int m = l + (r - l) / 2;
        solve(arr, l, m, count);
        solve(arr, m + 1, r, count);
        mergeAndCount(arr, l, m, r, count);
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    Element *arr = (Element *)malloc(n * sizeof(Element));
    int *count = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].value);
        arr[i].original_idx = i;
    }

    solve(arr, 0, n - 1, count);

    for (int i = 0; i < n; i++) {
        printf("%d%s", count[i], (i == n - 1) ? "" : " ");
    }
    printf("\n");

    free(arr);
    free(count);
    return 0;
}