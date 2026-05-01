#include <stdio.h>
#include <stdlib.h>

/**
 * Merges two sorted subarrays and counts cross-inversions.
 * An inversion is counted when an element from the right subarray (R)
 * is smaller than an element from the left subarray (L).
 */
long long mergeAndCount(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    long long count = 0;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            // Since L is sorted, if L[i] > R[j], then all elements
            // from L[i] to L[n1-1] are also greater than R[j].
            arr[k++] = R[j++];
            count += (n1 - i);
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
    return count;
}

/**
 * Standard Merge Sort logic modified to return inversion counts.
 */
long long countInversions(int arr[], int l, int r) {
    long long count = 0;
    if (l < r) {
        int m = l + (r - l) / 2;
        count += countInversions(arr, l, m);
        count += countInversions(arr, m + 1, r);
        count += mergeAndCount(arr, l, m, r);
    }
    return count;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    if (n <= 1) {
        // For size 0 or 1, there are 0 inversions
        int dummy;
        for(int i=0; i<n; i++) scanf("%d", &dummy);
        printf("0\n");
        return 0;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%lld\n", countInversions(arr, 0, n - 1));

    free(arr);
    return 0;
}