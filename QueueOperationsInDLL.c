#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = item;
    newNode->next = NULL;
    newNode->prev = rear;
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Enqueued %d into the queue.\n", item);
}

int dequeue() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return -1; 
    }
    struct Node* temp = front;
    int data = temp->data;
    front = front->next;
    if (front != NULL) {
        front->prev = NULL;
    } else {
        rear = NULL; 
    }
    free(temp);
    return data;
}

void display() {
    struct Node* current = front;
    if (current == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int choice, item;
    
    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to enqueue: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                item = dequeue();
                if (item != -1) {
                    printf("Dequeued item: %d\n", item);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

