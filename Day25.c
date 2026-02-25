// Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.
//
// Input:
// - First line: integer n (number of nodes)
// - Second line: n space-separated integers (linked list elements)
// - Third line: integer key (element to be counted)
//
// Output:
// - Print the number of times the key appears in the linked list
//
// Example:
// Input:
// 6
// 10 20 30 20 40 20
// 20
//
// Output:
// 3
//
// Explanation:
// Traverse the linked list from head to end. Each time a node's data matches the given key, increment a counter. After traversal, print the final count.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int key) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = key;
    temp->next = NULL;
    return temp;
}

Node* insert(Node* head, int data) {
    Node* node = createNode(data);
    if (!head) return node;
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = node;
    return head;
}


int countNode(Node* head, int key) {
    Node* temp = head;
    int count = 0;
    while (temp != NULL) {
        if (temp->data == key) {
            count++;
        }
        temp = temp->next;
    }
    return count;
}


int main() {

    int n;
    scanf("%d", &n);
    int val;
    Node* head = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        head = insert(head, val);
    }

    int count = countNode(head, val);
    printf("\n%d\n", count);


    return 0;
}