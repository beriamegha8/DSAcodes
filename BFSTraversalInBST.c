#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct QueueNode {
    struct TreeNode* data;
    struct QueueNode* next;
};

// Structure to represent a queue
struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

// Function to create a new node for the tree
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to enqueue a tree node to the queue
void enqueue(struct Queue* q, struct TreeNode* treeNode) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = treeNode;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Function to dequeue a tree node from the queue
struct TreeNode* dequeue(struct Queue* q) {
    if (q->front == NULL)
        return NULL;
    struct QueueNode* temp = q->front;
    struct TreeNode* treeNode = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return treeNode;
}

// Function to perform BFS in a tree
void breadthFirstSearch(struct TreeNode* root) {
    if (root == NULL)
        return;

    struct Queue* queue = createQueue();
    enqueue(queue, root);

    while (queue->front) {
        struct TreeNode* currentNode = dequeue(queue);
        printf("%d ", currentNode->data);

        if (currentNode->left)
            enqueue(queue, currentNode->left);
        if (currentNode->right)
            enqueue(queue, currentNode->right);
    }

    free(queue);
}

int main() {
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Breadth-First Traversal of the tree: ");
    breadthFirstSearch(root);

    return 0;
}

