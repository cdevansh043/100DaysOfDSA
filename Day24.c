// Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.
//
// Input:
// - First line: integer n
// - Second line: n space-separated integers
// - Third line: integer key
//
// Output:
// - Print the linked list elements after deletion, space-separated
//
// Example:
// Input:
// 5
// 10 20 30 40 50
// 30
//
// Output:
// 10 20 40 50
//
// Explanation:
// Traverse list, find first node with key, remove it by adjusting previous node's next pointer.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

Node* insert(Node* head, int data) {
    Node* node = createNode(data);
    if (!head) return node;
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = node;
    return head;
}

void deleteNode(Node* head, int key) {
    Node* temp = head;
    Node* prev = NULL;
    while (temp != NULL) {
        if (temp->data == key) {
            if (prev) prev->next = temp->next;
            else head = temp->next;
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Key not found\n");
    exit(1);

}

void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n;
    int val;
    scanf("%d", &n);
    Node* head = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        head = insert(head, val);
    }
    int key;
    scanf("%d", &key);
    deleteNode(head, key);
    display(head);

    return 0;
}