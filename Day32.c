// Problem: Implement push and pop operations on a stack and verify stack operations.
//
// Input:
// - First line: integer n
// - Second line: n integers to push
// - Third line: integer m (number of pops)
//
// Output:
// - Print remaining stack elements from top to bottom
//
// Example:
// Input:
// 5
// 10 20 30 40 50
// 2
//
// Output:
// 30 20 10


#include <stdio.h>

#define MAX 1000

int stack[MAX];
int top = -1;

void push(int item) {
    stack[++top] = item;
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    }else {
        stack[top--];
    }
}

void display() {
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    int n;
    scanf("%d",&n);

    for (int i = 1; i <= n; i++) {
        int item;
        scanf("%d",&item);
        push(item);
    }
    int m;
    scanf("%d",&m);
    for (int i = 1; i <= m; i++) {
        pop();
    }
    display();

    return 0;
}