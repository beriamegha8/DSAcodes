#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = item;
    newNode->next = top;
    top = newNode;
    printf("Pushed %d onto the stack.\n", item);
}

int pop() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return -1; // Return a sentinel value to indicate an empty stack
    }
    struct Node* temp = top;
    int data = temp->data;
    top = temp->next;
    free(temp);
    return data;
}

void display() {
    struct Node* current = top;
    if (current == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int choice, item;
    
    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to push: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                item = pop();
                if (item != -1) {
                    printf("Popped item: %d\n", item);
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

