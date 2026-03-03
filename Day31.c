// Problem: Implement a stack data structure using an array with the following operations: push, pop, and display.
//
// Input:
// - First line: integer n (number of operations)
// - Next n lines: operation type and value (if applicable)
//   - 1 value: push value
//   - 2: pop
//   - 3: display
//
// Output:
// - For display: print stack elements from top to bottom
// - For pop: print popped element or 'Stack Underflow'
//
// Example:
// Input:
// 5
// 1 10
// 1 20
// 3
// 2
// 3
//
// Output:
// 20 10
// 20
// 10

#include <stdio.h>

#define MAX 1000

int stack[MAX];
int top = -1;

void push(int val) {
    stack[++top] = val;
}

void pop() {
    if (top == -1)
        printf("Stack Underflow\n");
    else
        printf("%d\n", stack[top--]);
}

void display() {
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    int n, op, val;
    scanf("%d", &n);

    while (n--) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d", &val);
            push(val);
        } else if (op == 2) {
            pop();
        } else if (op == 3) {
            display();
        }
    }
    return 0;
}