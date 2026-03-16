// Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.
//
// Input:
// - First line: integer n (number of elements)
// - Second line: n space-separated integers
//
// Output:
// - Print queue elements from front to rear, space-separated
//
// Example:
// Input:
// 5
// 10 20 30 40 50
//
// Output:
// 10 20 30 40 50
//
// Explanation:
// Use array and front/rear pointers. Enqueue inserts at rear, dequeue removes from front. Display from front to rear.

#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
struct Node {
    int data;
    struct Node* next;
};

// Queue structure with front and rear pointers
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Initialize queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue: insert at rear
void enqueue(struct Queue* q, int data) {
    struct Node* newNode = createNode(data);
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

// Display queue from front to rear
void display(struct Queue* q) {
    struct Node* temp = q->front;
    while (temp != NULL) {
        if (temp->next == NULL)
            printf("%d", temp->data);
        else
            printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Free all allocated memory
void freeQueue(struct Queue* q) {
    struct Node* temp = q->front;
    while (temp != NULL) {
        struct Node* next = temp->next;
        free(temp);
        temp = next;
    }
    free(q);
}

int main() {
    int n, val;
    scanf("%d", &n);

    struct Queue* q = createQueue();

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(q, val);
    }

    display(q);
    freeQueue(q);

    return 0;
}