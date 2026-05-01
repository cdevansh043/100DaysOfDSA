#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

int compareIntervals(const void* a, const void* b) {
    Interval* i1 = (Interval*)a;
    Interval* i2 = (Interval*)b;
    if (i1->start != i2->start) {
        return i1->start - i2->start;
    }
    return i1->end - i2->end;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

void mergeIntervals(Interval intervals[], int n) {
    if (n <= 0) return;

    qsort(intervals, n, sizeof(Interval), compareIntervals);

    int index = 0;

    for (int i = 1; i < n; i++) {
        if (intervals[index].end >= intervals[i].start) {
            intervals[index].end = max(intervals[index].end, intervals[i].end);
        } else {
            index++;
            intervals[index] = intervals[i];
        }
    }

    for (int i = 0; i <= index; i++) {
        printf("%d %d\n", intervals[i].start, intervals[i].end);
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    Interval *intervals = (Interval *)malloc(n * sizeof(Interval));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i].start, &intervals[i].end);
    }

    mergeIntervals(intervals, n);

    free(intervals);
    return 0;
}