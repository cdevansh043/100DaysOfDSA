// Problem: Create and Traverse Singly Linked List
//
// Input:
// - First line: integer n
// - Second line: n space-separated integers
//
// Output:
// - Print the result
//
// Example:
// Input:
// 5
// 10 20 30 40 50
//
// Output:
// 10 20 30 40 50

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* head = NULL;
    struct Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        struct Node* node = createNode(val);
        if (head == NULL) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    struct Node* curr = head;
    while (curr != NULL) {
        if (curr->next == NULL)
            printf("%d", curr->data);
        else
            printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("\n");

    curr = head;
    while (curr != NULL) {
        struct Node* temp = curr;
        curr = curr->next;
        free(temp);
    }

    return 0;
}
