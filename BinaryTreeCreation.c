#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else {
        struct Node* temp = root;
        while (1) {
            int c;
            printf("You want to enter in the left or right of %d? (1 for left / 2 for right): ", temp->data);
            scanf("%d", &c);

            struct Node* newNode = createNode(data);

            if (c == 1) {
                if (temp->left == NULL) {
                    temp->left = newNode;
                    break;
                } else {
                    temp = temp->left;
                }
            } else {
                if (temp->right == NULL) {
                    temp->right = newNode;
                    break;
                } else {
                    temp = temp->right;
                }
            }
        }
        return root;
    }
}

struct Node* deleteNode(struct Node* root, struct Node* nodeToDelete) {
    if (root == NULL) {
        return root;
    }

    // Find the node to be deleted
    if (root == nodeToDelete) {
        free(root);
        return NULL;  // Returning NULL as the new root after deletion
    }

    // Recursively delete in the left and right subtrees
    root->left = deleteNode(root->left, nodeToDelete);
    root->right = deleteNode(root->right, nodeToDelete);

    return root;
}

// Function to perform an in-order traversal of the binary tree
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, data;

    printf("Binary Tree Creation:\n");

    do {
        printf("Enter data to insert: ");
        scanf("%d", &data);
        root = insert(root, data);

        printf("Do you want to insert more nodes? (1/0): ");
        scanf("%d", &choice);
    } while (choice != 0);

    printf("In-order Traversal of Binary Tree before deletion: ");
    inorderTraversal(root);
    printf("\n");

    root = deleteNode(root, root);

    printf("In-order traversal after deletion: ");
    inorderTraversal(root);
    printf("\n");


    return 0;
}

