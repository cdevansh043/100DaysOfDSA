#include <stdio.h>
#include <stdlib.h>

// Node structure for individual buckets (Linked List)
struct Node {
    float data;
    struct Node* next;
};

// Function to sort individual buckets using Insertion Sort
struct Node* insertionSort(struct Node* head) {
    if (!head || !head->next) return head;

    struct Node* sorted = NULL;
    struct Node* current = head;

    while (current) {
        struct Node* next = current->next;
        if (!sorted || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            struct Node* temp = sorted;
            while (temp->next && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    return sorted;
}

void bucketSort(float arr[], int n) {
    // 1. Create n empty buckets
    struct Node** buckets = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++) {
        buckets[i] = NULL;
    }

    // 2. Put array elements in different buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)(n * arr[i]);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = arr[i];
        newNode->next = buckets[bucketIndex];
        buckets[bucketIndex] = newNode;
    }

    // 3. Sort individual buckets and concatenate
    int index = 0;
    for (int i = 0; i < n; i++) {
        buckets[i] = insertionSort(buckets[i]);
        struct Node* curr = buckets[i];
        while (curr) {
            arr[index++] = curr->data;
            struct Node* temp = curr;
            curr = curr->next;
            free(temp); // Clean up memory
        }
    }
    free(buckets);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    if (n <= 0) return 0;

    float *arr = (float *)malloc(n * sizeof(float));
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    bucketSort(arr, n);

    for (int i = 0; i < n; i++) {
        // Handling float precision to match expected output styles
        printf("%g%s", arr[i], (i == n - 1) ? "" : " ");
    }
    printf("\n");

    free(arr);
    return 0;
}