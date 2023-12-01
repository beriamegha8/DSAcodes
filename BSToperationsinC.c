#include <stdio.h>
#include <stdlib.h>

// Structure for a doubly linked list node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

int count = 0;
int flag = 0;

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

// Function to perform an inorder traversal of the BST
void InorderTraversal(struct Node* root) {
    if (root != NULL) {
        InorderTraversal(root->left);
        printf("%d ", root->data);
        InorderTraversal(root->right);
    }
}

// Function to perform a preorder traversal of the BST
void PreorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        PreorderTraversal(root->left);
        PreorderTraversal(root->right);
    }
}

// Function to perform a postorder traversal of the BST
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

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root;

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

struct Node* copyTree(struct Node* originalRoot) {
    if (originalRoot == NULL) {
        return NULL;
    }

    // Create a new node with the same data
    struct Node* newRoot = createNode(originalRoot->data);

    // Recursively copy the left and right subtrees
    newRoot->left = copyTree(originalRoot->left);
    newRoot->right = copyTree(originalRoot->right);

    return newRoot;
}

struct Node* mirror(struct Node* originalRoot) {
    if (originalRoot == NULL) {
        return NULL;
    }

    // Create a new node with the same data
    struct Node* newRoot = createNode(originalRoot->data);

    // Recursively copy the left and right subtrees
    newRoot->left = mirror(originalRoot->right);
    newRoot->right = mirror(originalRoot->left);

    return newRoot;
}

// Function to count the total number of nodes
int CountTotal(struct Node* root) {
    if (root != NULL) {
        CountTotal(root->left);
        count++;
        CountTotal(root->right);
    }
    return count;
}

// Function to search for an element in the tree
void Search(struct Node* root, int key) {
    flag = 0;

    if (root != NULL) {
        Search(root->left, key);
        if (key == root->data) {
            flag = 1;
            printf("%d found", key);
            return;
        }
        // Add the return statement here to stop searching in the right subtree
        return;
        Search(root->right, key);
    }
    if (flag == 0) {
        printf("%d not found", key);
    }
}

// Function to count leaf nodes in a tree
int countLeafNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }

    if (root->left == NULL && root->right == NULL) {
        // This is a leaf node
        return 1;
    }

    // Recursively count leaf nodes in the left and right subtrees
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    struct Node* root = NULL;
    int choice, data, element;
    int key;

    printf("Binary Search Tree Creation-\n");

    do {
        printf("Enter data to insert: ");
        scanf("%d", &data);
        root = insert(root, data);

        printf("Do you want to insert more nodes? (1/0): ");
        scanf("%d", &choice);
    } while (choice != 0);

    printf("Inorder Traversal of BST before deletion: ");
    InorderTraversal(root);
    printf("\n");

    printf("Preorder Traversal of BST before deletion: ");
    PreorderTraversal(root);
    printf("\n");

    printf("Postorder Traversal of BST before deletion: ");
    PostorderTraversal(root);
    printf("\n");

    // Copy the data to a new binary tree
    struct Node* newTree = copyTree(root);
    printf("New Tree In-order Traversal: ");
    InorderTraversal(newTree);
    printf("\n");

    // Mirror the data to a new binary tree
    struct Node* mirrorTree = mirror(root);
    printf("Mirror Tree In-order Traversal: ");
    InorderTraversal(mirrorTree);
    printf("\n");

    // Count the leaf nodes
    int leafCount = countLeafNodes(root);
    printf("Number of leaf nodes in the tree: %d\n", leafCount);
    printf("\n");

    count = 0; // Reset the count for the next function call

    int totalNodes = CountTotal(root);
    printf("Total number of nodes in the tree: %d\n", totalNodes);
    printf("\n");

    printf("Enter the element to be searched: ");
    scanf("%d", &element);
    Search(root, element);
    printf("\n");

    printf("Enter the data to be deleted: ");
    scanf("%d", &key);
    root = deleteNode(root, key);

    printf("Inorder traversal after deletion of %d: ", key);
    InorderTraversal(root);
    printf("\n");

    return 0;
}
