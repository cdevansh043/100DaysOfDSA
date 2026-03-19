// Problem Statement:
// Given a queue of integers, reverse the queue using a stack.
//
// Input Format:
// - First line contains integer N
// - Second line contains N space-separated integers
//
// Output Format:
// - Print the reversed queue
//
// Example:
// Input:
// 5
// 10 20 30 40 50
//
// Output:
// 50 40 30 20 10


#include <stdio.h>
#include <stdlib.h>

int stack[1000];
int top = -1;

void push(int val) {
    stack[++top] = val;
}

int pop() {
    return stack[top--];
}

int main() {
    int n;
    scanf("%d", &n);
    int queue[1000];
    for (int i = 0; i < n; i++)
        scanf("%d", &queue[i]);
    for (int i = 0; i < n; i++)
        push(queue[i]);
    for (int i = 0; i < n; i++)
        queue[i] = pop();
    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", queue[i]);
    }
    printf("\n");
    return 0;
}