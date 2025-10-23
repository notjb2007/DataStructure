#include <stdio.h>
#include <stdlib.h>

// ---------- STRUCTURE DEFINITIONS ----------
struct TreeNode;
typedef struct TreeNode *SearchTree;

struct TreeNode {
    int Element;
    SearchTree Left;
    SearchTree Right;
};

// ---------- FUNCTION DECLARATIONS ----------
SearchTree MakeEmpty(SearchTree T);
SearchTree Insert(int X, SearchTree T);
SearchTree Delete(int X, SearchTree T);
int Find(int X, SearchTree T);
int FindMin(SearchTree T);
int FindMax(SearchTree T);
void Inorder(SearchTree T);

// ---------- FUNCTION DEFINITIONS ----------

// Make the tree empty
SearchTree MakeEmpty(SearchTree T) {
    if (T != NULL) {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}

// Insert an element into the BST
SearchTree Insert(int X, SearchTree T) {
    if (T == NULL) {
        T = (SearchTree)malloc(sizeof(struct TreeNode));
        if (T == NULL)
            printf("Out of space!\n");
        else {
            T->Element = X;
            T->Left = T->Right = NULL;
        }
    } else if (X < T->Element)
        T->Left = Insert(X, T->Left);
    else if (X > T->Element)
        T->Right = Insert(X, T->Right);
    return T;
}

// Delete an element from the BST
SearchTree Delete(int X, SearchTree T) {
    struct TreeNode *temp;

    if (T == NULL)
        return NULL;
    else if (X < T->Element)
        T->Left = Delete(X, T->Left);
    else if (X > T->Element)
        T->Right = Delete(X, T->Right);
    else {
        if (T->Left && T->Right) {
            temp = T->Right;
            while (temp->Left != NULL)
                temp = temp->Left;
            T->Element = temp->Element;
            T->Right = Delete(T->Element, T->Right);
        } else {
            temp = T;
            if (T->Left == NULL)
                T = T->Right;
            else if (T->Right == NULL)
                T = T->Left;
            free(temp);
        }
    }
    return T;
}

// Search an element in the BST
int Find(int X, SearchTree T) {
    if (T == NULL)
        return 0;
    else if (X < T->Element)
        return Find(X, T->Left);
    else if (X > T->Element)
        return Find(X, T->Right);
    else
        return 1;
}

// Find Minimum element
int FindMin(SearchTree T) {
    if (T == NULL) {
        printf("Tree is empty\n");
        return -1;
    } else if (T->Left == NULL)
        return T->Element;
    else
        return FindMin(T->Left);
}

// Find Maximum element
int FindMax(SearchTree T) {
    if (T == NULL) {
        printf("Tree is empty\n");
        return -1;
    } else if (T->Right == NULL)
        return T->Element;
    else
        return FindMax(T->Right);
}

// Inorder Traversal (L → Root → R)
void Inorder(SearchTree T) {
    if (T != NULL) {
        Inorder(T->Left);
        printf("%d ", T->Element);
        Inorder(T->Right);
    }
}

// ---------- MAIN FUNCTION ----------
int main() {
    SearchTree T = NULL;
    int choice, value;

    while (1) {
        printf("\n\n--- Binary Search Tree Operations ---\n");
        printf("1. Insert\n2. Delete\n3. Find\n4. Find Minimum\n5. Find Maximum\n6. Display (Inorder)\n7. Make Empty\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            T = Insert(value, T);
            break;
        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            T = Delete(value, T);
            break;
        case 3:
            printf("Enter value to find: ");
            scanf("%d", &value);
            if (Find(value, T))
                printf("%d found in the tree.\n", value);
            else
                printf("%d not found.\n", value);
            break;
        case 4:
            printf("Minimum element: %d\n", FindMin(T));
            break;
        case 5:
            printf("Maximum element: %d\n", FindMax(T));
            break;
        case 6:
            printf("Inorder traversal: ");
            Inorder(T);
            printf("\n");
            break;
        case 7:
            T = MakeEmpty(T);
            printf("Tree cleared.\n");
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
