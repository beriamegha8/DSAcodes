#include <stdio.h>
#include <stdlib.h>

// Structure for a doubly linked list node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
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

// Function to insert a node into the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

//Function to perform an inorder traversal of the BST
void InorderTraversal(struct Node* root) {
    if (root != NULL) {
        InorderTraversal(root->left);
        printf("%d ", root->data);
        InorderTraversal(root->right);
    }
}

//Function to perform an preorder traversal of the BST
void PreorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        PreorderTraversal(root->left);
        PreorderTraversal(root->right);
    }
}

//Function to perform an postorder traversal of the BST
void PostorderTraversal(struct Node* root) {
    if (root != NULL) {
        PostorderTraversal(root->left);
        PostorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Function to find the minimum value node in a tree
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

// Function to delete a node with a given key in a BST
struct Node* deleteNode(struct Node* root, int key) {
    // Base case: If the tree is empty
    if (root == NULL)
        return root;

    // Recursively find and delete the node in the left or right subtree
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = minValueNode(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    struct Node* root= NULL;
    int choice, data;
    int key;

    printf("Binary Search Tree Creation-\n");

    do {
        printf("Enter data to insert: ");
        scanf("%d", &data);
        root= insert(root, data);

        printf("Do you want to insert more nodes? (1/0): ");
        scanf("%d", &choice);
    } while (choice!= 0);

    printf("Inorder Traversal of BST before deletion: ");
    InorderTraversal(root);
    printf("\n");
    
    printf("Level Order BFS Traversal of BST before deletion: ");
    LevelOrderTraversal(root);
    printf("\n");
    
    printf("Enter the data to be deleted: ");
    scanf("%d", &key);
    root = deleteNode(root, key);

    printf("Inorder traversal after deletion of %d: ", key);
    InorderTraversal(root);
    printf("\n");
    
    printf("Level Order BFS Traversal of BST after deletion: ");
    LevelOrderTraversal(root);
    printf("\n");
    
    return 0;
}
