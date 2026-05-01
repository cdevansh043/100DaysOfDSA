#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

// Comparator to sort intervals by start time
int compareIntervals(const void* a, const void* b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

// Simple Min-Heap implementation for end times
void heapify(int heap[], int size, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && heap[l] < heap[smallest]) smallest = l;
    if (r < size && heap[r] < heap[smallest]) smallest = r;

    if (smallest != i) {
        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        heapify(heap, size, smallest);
    }
}

void push(int heap[], int *size, int val) {
    heap[*size] = val;
    int i = *size;
    (*size)++;
    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        int temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

void pop(int heap[], int *size) {
    heap[0] = heap[*size - 1];
    (*size)--;
    heapify(heap, *size, 0);
}

int minMeetingRooms(Interval intervals[], int n) {
    if (n == 0) return 0;

    // 1. Sort intervals by start time
    qsort(intervals, n, sizeof(Interval), compareIntervals);

    // 2. Min-heap to store end times of meetings in progress
    int *minHeap = (int *)malloc(n * sizeof(int));
    int heapSize = 0;

    // Add the end time of the first meeting
    push(minHeap, &heapSize, intervals[0].end);

    for (int i = 1; i < n; i++) {
        // If the earliest room available is free before the current meeting starts
        if (intervals[i].start >= minHeap[0]) {
            pop(minHeap, &heapSize);
        }
        // Add current meeting's end time (either reusing or adding a room)
        push(minHeap, &heapSize, intervals[i].end);
    }

    int result = heapSize;
    free(minHeap);
    return result;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    Interval *intervals = (Interval *)malloc(n * sizeof(Interval));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i].start, &intervals[i].end);
    }

    printf("%d\n", minMeetingRooms(intervals, n));

    free(intervals);
    return 0;
}