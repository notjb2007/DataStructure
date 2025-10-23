#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Node structure
struct Node {
    char data;
    struct Node *left, *right;
};

// Stack for nodes
struct Node* stack[100];
int top = -1;

// Push node to stack
void push(struct Node* node) {
    stack[++top] = node;
}

// Pop node from stack
struct Node* pop() {
    return stack[top--];
}

// Create a new node
struct Node* newNode(char data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Build expression tree from postfix
struct Node* buildTree(char* postfix) {
    int i;
    char ch;
    struct Node *node, *left, *right;

    for (i = 0; postfix[i]; i++) {
        ch = postfix[i];

        if (isalnum(ch)) { // Operand
            node = newNode(ch);
            push(node);
        } else { // Operator
            node = newNode(ch);
            right = pop();
            left = pop();
            node->left = left;
            node->right = right;
            push(node);
        }
    }

    return pop(); // Root of tree
}

// Inorder traversal (prints infix)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

// Preorder traversal
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->data);
    }
}

// Main function
int main() {
    char postfix[100];
    struct Node* root;

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    root = buildTree(postfix);

    printf("Inorder (infix): ");
    inorder(root);
    printf("\n");

    printf("Preorder (prefix): ");
    preorder(root);
    printf("\n");

    printf("Postorder (postfix): ");
    postorder(root);
    printf("\n");

    return 0;
}
