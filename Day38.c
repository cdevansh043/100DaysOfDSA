// Problem: Deque (Double-Ended Queue)
//
// A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.
//
// Common Operations:
// 1. push_front(value): Insert an element at the front of the deque.
// 2. push_back(value): Insert an element at the rear of the deque.
// 3. pop_front(): Remove an element from the front of the deque.
// 4. pop_back(): Remove an element from the rear of the deque.
// 5. front(): Return the front element of the deque.
// 6. back(): Return the rear element of the deque.
// 7. empty(): Check whether the deque is empty.
// 8. size(): Return the number of elements in the deque.
//
// Additional Operations:
// - clear(): Remove all elements from the deque.
// - erase(): Remove one or more elements from the deque.
// - swap(): Swap contents of two deques.
// - emplace_front(): Insert an element at the front without copying.
// - emplace_back(): Insert an element at the rear without copying.
// - resize(): Change the size of the deque.
// - assign(): Replace elements with new values.
// - reverse(): Reverse the order of elements.
// - sort(): Sort the elements in ascending order.
//
// Time Complexity:
// - push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
// - clear, erase, resize, assign, reverse: O(n)
// - sort: O(n log n)
//
// Input:
// - Sequence of deque operations with values (if applicable)
//
// Output:
// - Results of operations such as front, back, size, or the final state of the deque after all operations


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ── Node ────────────────────────────────────────────────────── */
typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

/* ── Deque ───────────────────────────────────────────────────── */
typedef struct {
    Node *head, *tail;
    int   sz;
} Deque;

/* ── Helpers ─────────────────────────────────────────────────── */
Node *newNode(int v) {
    Node *n = malloc(sizeof(Node));
    n->data = v; n->prev = n->next = NULL;
    return n;
}

void initDeque(Deque *d) { d->head = d->tail = NULL; d->sz = 0; }

/* ── Core O(1) ops ───────────────────────────────────────────── */
void push_front(Deque *d, int v) {
    Node *n = newNode(v);
    if (!d->head) { d->head = d->tail = n; }
    else { n->next = d->head; d->head->prev = n; d->head = n; }
    d->sz++;
}

void push_back(Deque *d, int v) {
    Node *n = newNode(v);
    if (!d->tail) { d->head = d->tail = n; }
    else { n->prev = d->tail; d->tail->next = n; d->tail = n; }
    d->sz++;
}

int pop_front(Deque *d) {
    if (!d->head) { printf("Deque is empty\n"); return -1; }
    Node *tmp = d->head; int v = tmp->data;
    d->head = d->head->next;
    if (d->head) d->head->prev = NULL; else d->tail = NULL;
    free(tmp); d->sz--;
    return v;
}

int pop_back(Deque *d) {
    if (!d->tail) { printf("Deque is empty\n"); return -1; }
    Node *tmp = d->tail; int v = tmp->data;
    d->tail = d->tail->prev;
    if (d->tail) d->tail->next = NULL; else d->head = NULL;
    free(tmp); d->sz--;
    return v;
}

int front(Deque *d) {
    if (!d->head) { printf("Deque is empty\n"); return -1; }
    return d->head->data;
}

int back(Deque *d) {
    if (!d->tail) { printf("Deque is empty\n"); return -1; }
    return d->tail->data;
}

int empty(Deque *d)  { return d->sz == 0; }
int sizeD(Deque *d)  { return d->sz; }

/* ── Additional ops ──────────────────────────────────────────── */
void clear(Deque *d) {
    while (d->head) { Node *t = d->head; d->head = d->head->next; free(t); }
    d->tail = NULL; d->sz = 0;
}

/* erase node at 0-based position idx */
void eraseAt(Deque *d, int idx) {
    if (idx < 0 || idx >= d->sz) { printf("Index out of range\n"); return; }
    Node *cur = d->head;
    for (int i = 0; i < idx; i++) cur = cur->next;
    if (cur->prev) cur->prev->next = cur->next; else d->head = cur->next;
    if (cur->next) cur->next->prev = cur->prev; else d->tail = cur->prev;
    free(cur); d->sz--;
}

void swapDeques(Deque *a, Deque *b) {
    Deque tmp = *a; *a = *b; *b = tmp;
}

/* emplace = push (no separate struct to copy, so identical to push) */
void emplace_front(Deque *d, int v) { push_front(d, v); }
void emplace_back (Deque *d, int v) { push_back (d, v); }

void resizeDeque(Deque *d, int newSz, int fillVal) {
    while (d->sz > newSz) pop_back(d);
    while (d->sz < newSz) push_back(d, fillVal);
}

void assign(Deque *d, int count, int v) {
    clear(d);
    for (int i = 0; i < count; i++) push_back(d, v);
}

void reverseDeque(Deque *d) {
    Node *cur = d->head;
    while (cur) { Node *t = cur->next; cur->next = cur->prev; cur->prev = t; cur = t; }
    Node *t = d->head; d->head = d->tail; d->tail = t;
}

/* copy to array → sort → rebuild */
void sortDeque(Deque *d) {
    if (d->sz < 2) return;
    int *arr = malloc(d->sz * sizeof(int));
    Node *cur = d->head;
    for (int i = 0; i < d->sz; i++, cur = cur->next) arr[i] = cur->data;

    /* insertion sort — fine for typical contest sizes */
    for (int i = 1; i < d->sz; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) { arr[j+1] = arr[j]; j--; }
        arr[j+1] = key;
    }
    cur = d->head;
    for (int i = 0; i < d->sz; i++, cur = cur->next) cur->data = arr[i];
    free(arr);
}

/* ── Display ─────────────────────────────────────────────────── */
void display(Deque *d) {
    if (!d->head) { printf("[empty]\n"); return; }
    Node *cur = d->head;
    printf("[");
    while (cur) { printf("%d", cur->data); if (cur->next) printf(" <-> "); cur = cur->next; }
    printf("]\n");
}

/* ══════════════════════════════════════════════════════════════
   DEMO – exercises every operation
   ══════════════════════════════════════════════════════════════ */
int main(void) {
    Deque d, d2;
    initDeque(&d); initDeque(&d2);

    printf("=== push_back: 10 20 30 ===\n");
    push_back(&d, 10); push_back(&d, 20); push_back(&d, 30);
    display(&d);

    printf("\n=== push_front: 5 ===\n");
    push_front(&d, 5);
    display(&d);

    printf("\n=== front=%d  back=%d ===\n", front(&d), back(&d));

    printf("\n=== pop_front → %d ===\n", pop_front(&d));
    display(&d);

    printf("\n=== pop_back  → %d ===\n", pop_back(&d));
    display(&d);

    printf("\n=== size=%d  empty=%d ===\n", sizeD(&d), empty(&d));

    printf("\n=== emplace_front(1)  emplace_back(99) ===\n");
    emplace_front(&d, 1); emplace_back(&d, 99);
    display(&d);

    printf("\n=== erase index 1 ===\n");
    eraseAt(&d, 1);
    display(&d);

    printf("\n=== reverse ===\n");
    reverseDeque(&d);
    display(&d);

    printf("\n=== push_back 5 15 3  then sort ===\n");
    push_back(&d, 5); push_back(&d, 15); push_back(&d, 3);
    sortDeque(&d);
    display(&d);

    printf("\n=== resize to 6 (fill 0) ===\n");
    resizeDeque(&d, 6, 0);
    display(&d);

    printf("\n=== assign: 4 × 7 ===\n");
    assign(&d, 4, 7);
    display(&d);

    printf("\n=== swap with d2 (d2 has 100 200) ===\n");
    push_back(&d2, 100); push_back(&d2, 200);
    swapDeques(&d, &d2);
    printf("d  : "); display(&d);
    printf("d2 : "); display(&d2);

    printf("\n=== clear d ===\n");
    clear(&d);
    printf("empty=%d\n", empty(&d));

    return 0;
}