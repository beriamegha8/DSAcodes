#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 1000

typedef struct {
    int stack[MAX_SIZE];
    int top;
} Stack;

void push(Stack *s, int value) {
    s->stack[s->top++] = value;
}

int pop(Stack *s) {
    return s->stack[--s->top];
}

int peek(Stack *s) {
    return s->stack[s->top - 1];
}

bool is_empty(Stack *s) {
    return s->top == 0;
}

int main() {
    char menu[] = "1. Push\n2. Pop\n3. Peek\n4. Is Empty\n5. Exit\n";
    int choice;
    Stack stack = { .top = 0 };

    while (true) {
        printf("%s", menu);
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a valid integer choice.\n");
            while (getchar() != '\n'); // Clear the input buffer
            continue;
        }

        switch (choice) {
            case 1: {
                int value;
                printf("Enter value: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input. Please enter a valid integer value.\n");
                    while (getchar() != '\n'); // Clear the input buffer
                    continue;
                }
                push(&stack, value);
                break;
            }
            case 2: {
                if (!is_empty(&stack)) {
                    printf("Popped: %d\n", pop(&stack));
                } else {
                    printf("The stack is empty.\n");
                }
                break;
            }
            case 3: {
                if (!is_empty(&stack)) {
                    printf("Peeked: %d\n", peek(&stack));
                } else {
                    printf("The stack is empty.\n");
                }
                break;
            }
            case 4: {
                printf("%s\n", is_empty(&stack) ? "The stack is empty" : "The stack is not empty");
                break;
            }
            case 5: {
                return 0;
            }
            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    }
}

