#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in a binary tree
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Structure to represent a node in the stack used for DFS
struct StackNode {
    struct TreeNode* data;
    struct StackNode* next;
};

// Structure to represent a stack
struct Stack {
    struct StackNode* top;
};

// Function to create a new node for the binary tree
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to create an empty stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

// Function to push a tree node to the stack
void push(struct Stack* stack, struct TreeNode* treeNode) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = treeNode;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop a tree node from the stack
struct TreeNode* pop(struct Stack* stack) {
    if (stack->top == NULL)
        return NULL;
    struct StackNode* temp = stack->top;
    struct TreeNode* treeNode = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return treeNode;
}

// Function to perform Preorder iterative DFS
void preorderIterativeDFS(struct TreeNode* root) {
    if (root == NULL)
        return;

    struct Stack* stack = createStack();
    push(stack, root);

    printf("Preorder Iterative DFS: ");
    while (stack->top) {
        struct TreeNode* currentNode = pop(stack);
        printf("%d ", currentNode->data);

        if (currentNode->right)
            push(stack, currentNode->right);
        if (currentNode->left)
            push(stack, currentNode->left);
    }

    free(stack);
}

// Function to perform Inorder iterative DFS
void inorderIterativeDFS(struct TreeNode* root) {
    if (root == NULL)
        return;

    struct Stack* stack = createStack();
    struct TreeNode* currentNode = root;

    printf("Inorder Iterative DFS: ");
    while (stack->top || currentNode) {
        while (currentNode) {
            push(stack, currentNode);
            currentNode = currentNode->left;
        }

        currentNode = pop(stack);
        printf("%d ", currentNode->data);
        currentNode = currentNode->right;
    }

    free(stack);
}

// Function to perform Postorder iterative DFS
void postorderIterativeDFS(struct TreeNode* root) {
    if (root == NULL)
        return;

    struct Stack* stack1 = createStack();
    struct Stack* stack2 = createStack();

    push(stack1, root);

    printf("Postorder Iterative DFS: ");
    while (stack1->top) {
        struct TreeNode* currentNode = pop(stack1);
        push(stack2, currentNode);

        if (currentNode->left)
            push(stack1, currentNode->left);
        if (currentNode->right)
            push(stack1, currentNode->right);
    }

    while (stack2->top) {
        struct TreeNode* currentNode = pop(stack2);
        printf("%d ", currentNode->data);
    }

    free(stack1);
    free(stack2);
}

int main() {
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    preorderIterativeDFS(root);
    printf("\n");
    inorderIterativeDFS(root);
    printf("\n");
    postorderIterativeDFS(root);
    printf("\n");

    return 0;
}

