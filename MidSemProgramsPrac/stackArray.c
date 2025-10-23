#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of stack

int stack[MAX];
int top = -1;

// Function to push an element into the stack
void push(int value) {
    if (top == MAX - 1)
        printf("Stack Overflow! Cannot push %d.\n", value);
    else {
        top++;
        stack[top] = value;
        printf("%d pushed to stack.\n", value);
    }
}

// Function to pop an element from the stack
void pop() {
    if (top == -1)
        printf("Stack Underflow! Nothing to pop.\n");
    else {
        printf("%d popped from stack.\n", stack[top]);
        top--;
    }
}

// Function to display all stack elements
void display() {
    if (top == -1)
        printf("Stack is empty!\n");
    else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

// Function to see the top element
void peek() {
    if (top == -1)
        printf("Stack is empty!\n");
    else
        printf("Top element: %d\n", stack[top]);
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\n---- Stack Using Array ----\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
