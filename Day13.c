// Problem: You are given a rectangular matrix of integers. Starting from the outer boundary, traverse the matrix in a clockwise manner and continue moving inward layer by layer until all elements are visited.
//
// Input:
// - First line: two integers r and c representing the number of rows and columns
// - Next r lines: c integers each representing the matrix elements
//
// Output:
// - Print all visited elements in the order of traversal, separated by spaces
//
// Example:
// Input:
// 3 3
// 1 2 3
// 4 5 6
// 7 8 9
//
// Output:
// 1 2 3 6 9 8 7 4 5
//
// Explanation:
// The traversal begins along the top row, proceeds down the rightmost column, then moves across the bottom row in reverse, and finally goes up the leftmost column. The same pattern repeats for the inner submatrix.
//
// Test Cases:
//
// Test Case 1:
// Input:
// 2 3
// 1 2 3
// 4 5 6
// Output:
// 1 2 3 6 5 4
//
// Test Case 2:
// Input:
// 3 1
// 7
// 8
// 9
// Output:
// 7 8 9
#include <stdio.h>
#include <stdlib.h>

void spiral_traversal(int** matrix, int r, int c) {
    int top = 0;
    int bottom = r - 1;
    int left = 0;
    int right = c - 1;
    int first = 1;

    while (top <= bottom && left <= right) {
        for (int col = left; col <= right; col++) {
            if (!first) printf(" ");
            printf("%d", matrix[top][col]);
            first = 0;
        }
        top++;

        for (int row = top; row <= bottom; row++) {
            if (!first) printf(" ");
            printf("%d", matrix[row][right]);
            first = 0;
        }
        right--;

        if (top <= bottom) {
            for (int col = right; col >= left; col--) {
                if (!first) printf(" ");
                printf("%d", matrix[bottom][col]);
                first = 0;
            }
            bottom--;
        }

        if (left <= right) {
            for (int row = bottom; row >= top; row--) {
                if (!first) printf(" ");
                printf("%d", matrix[row][left]);
                first = 0;
            }
            left++;
        }
    }
    printf("\n");
}

int main() {
    int r, c;

    scanf("%d %d", &r, &c);

    int** matrix = (int**)malloc(r * sizeof(int*));
    for (int i = 0; i < r; i++) {
        matrix[i] = (int*)malloc(c * sizeof(int));
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    spiral_traversal(matrix, r, c);

    for (int i = 0; i < r; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}