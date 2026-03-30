// Problem Statement:
// Construct a binary tree from given preorder and inorder traversal arrays.
//
// Input Format:
// - First line contains integer N
// - Second line contains preorder traversal
// - Third line contains inorder traversal
//
// Output Format:
// - Print postorder traversal of constructed tree
//
// Example:
// Input:
// 5
// 1 2 4 5 3
// 4 2 5 1 3
//
// Output:
// 4 5 2 3 1
//
// Explanation:
// Preorder identifies root, inorder splits left and right subtrees.

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode* newNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int findIndex(int* inorder, int n, int val) {
    for (int i = 0; i < n; i++)
        if (inorder[i] == val) return i;
    return -1;
}

TreeNode* build(int* preorder, int* inorder, int preStart, int inStart, int size) {
    if (size <= 0) return NULL;
    TreeNode* root = newNode(preorder[preStart]);
    int idx = findIndex(inorder, size, preorder[preStart]) - inStart;
    root->left = build(preorder, inorder, preStart + 1, inStart, idx);
    root->right = build(preorder, inorder, preStart + idx + 1, inStart + idx + 1, size - idx - 1);
    return root;
}

int first = 1;
void postorder(TreeNode* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    if (!first) printf(" ");
    printf("%d", root->val);
    first = 0;
}

int main() {
    int n;
    scanf("%d", &n);
    int* pre = (int*)malloc(n * sizeof(int));
    int* in  = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    TreeNode* root = build(pre, in, 0, 0, n);
    postorder(root);
    printf("\n");
    free(pre);
    free(in);
    return 0;
}