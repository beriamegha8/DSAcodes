#include <stdio.h>
#include <stdlib.h>

// Structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtStart(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}

// Function to insert a node at a specific position in the list
void insertAtPosition(struct Node** head, int data, int position) {
    if (position < 0) {
        printf("Invalid position for insertion\n");
        return;
    }

    struct Node* newNode = createNode(data);
    if (position == 0) {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    int currentPosition = 0;
    while (current != NULL && currentPosition < position - 1) {
        current = current->next;
        currentPosition++;
    }
    if (current == NULL) {
        printf("Invalid position for insertion\n");
        return;
    }
    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
}

// Function to delete a node from the start of the list
void deleteFromStart(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty, cannot delete from start\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

// Function to delete a node from the end of the list
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty, cannot delete from end\n");
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    if (current->prev != NULL) {
        current->prev->next = NULL;
    }
    free(current);
}

// Function to delete a node from a specific position in the list
void deleteFromPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty, cannot delete from position\n");
        return;
    }
    if (position < 0) {
        printf("Invalid position for deletion\n");
        return;
    }
    if (position == 0) {
        struct Node* temp = *head;
        *head = (*head)->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }

    struct Node* current = *head;
    int currentPosition = 0;
    while (current != NULL && currentPosition < position) {
        current = current->next;
        currentPosition++;
    }
    if (current == NULL) {
        printf("Invalid position for deletion\n");
        return;
    }
    if (current->prev != NULL) {
        current->prev->next = current->next;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    free(current);
}

// Function to traverse and print the linked list
void traverse(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to calculate the number of nodes in the linked list
int getCount(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Function to concatenate two linked lists
void concatenate(struct Node** list1, struct Node* list2) {
    if (*list1 == NULL) {
        *list1 = list2;
        return;
    }
    if (list2 == NULL) {
        return;
    }
    struct Node* current = *list1;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = list2;
    list2->prev = current;
}

// Function to reverse a linked list
void reverse(struct Node** head) {
    struct Node* temp = NULL;
    struct Node* current = *head;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL) {
        *head = temp->prev;
    }
}

// Function to sort a linked list in ascending order
void sort(struct Node** head) {
    struct Node* current = *head;
    struct Node* index = NULL;
    int temp;

    while (current != NULL) {
        index = current->next;
        while (index != NULL) {
            if (current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    }
}

// Function to search for a key in the linked list
int search(struct Node* head, int key, int* position) {
    struct Node* current = head;
    *position = 0;
    while (current != NULL) {
        if (current->data == key) {
            return 1; // Key found
        }
        current = current->next;
        (*position)++;
    }
    return 0; // Key not found
}

// Function to perform union of two linked lists
struct Node* unionLists(struct Node* list1, struct Node* list2) {
    struct Node* result = NULL;
    struct Node* current1 = list1;
    struct Node* current2 = list2;

    while (current1 != NULL) {
        insertAtEnd(&result, current1->data);
        current1 = current1->next;
    }

    while (current2 != NULL) {
        if (!search(result, current2->data, NULL)) {
            insertAtEnd(&result, current2->data);
        }
        current2 = current2->next;
    }

    return result;
}

// Function to perform intersection of two linked lists
struct Node* intersection(struct Node* list1, struct Node* list2) {
    struct Node* result = NULL;
    struct Node* current1 = list1;

    while (current1 != NULL) {
        int position;
        if (search(list2, current1->data, &position)) {
            insertAtEnd(&result, current1->data);
            printf("Key %d found at position %d in List 2\n", current1->data, position);
        }
        current1 = current1->next;
    }

    return result;
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    while (1) {
        printf("\nDoubly Linked List Operations\n");
        printf("1. Insert at start\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete from start\n");
        printf("5. Delete from end\n");
        printf("6. Delete from position\n");
        printf("7. Traverse\n");
        printf("8. Concatenate\n");
        printf("9. Reverse\n");
        printf("10. Sort\n");
        printf("11. Search\n");
        printf("12. Union\n");
        printf("13. Intersection\n");
        printf("14. Get Count\n");
        printf("15. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        int data, position;
        switch (choice) {
            case 1:
                printf("Enter data to insert at start: ");
                scanf("%d", &data);
                insertAtStart(&list1, data);
                traverse(list1);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&list1, data);
                traverse(list1);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(&list1, data, position);
                traverse(list1);
                break;
            case 4:
                deleteFromStart(&list1);
                traverse(list1);
                break;
            case 5:
                deleteFromEnd(&list1);
                traverse(list1);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteFromPosition(&list1, position);
                traverse(list1);
                break;
            case 7:
                printf("Linked List: ");
                traverse(list1);
                break;
            case 8:
                concatenate(&list1, list2);
                printf("Lists concatenated.\n");
                traverse(list1);
                break;
            case 9:
                reverse(&list1);
                printf("List reversed.\n");
                traverse(list1);
                break;
			case 10:
                sort(&list1);
                printf("List sorted in ascending order.\n");
                traverse(list1);
                break;
            case 11:
                printf("Enter a key to search: ");
                scanf("%d", &data);
                int found, position;
                found = search(list1, data, &position);
                if (found) {
                    printf("Key %d found at position %d in the list.\n", data, position);
                } else {
                    printf("Key %d not found in the list.\n", data);
                }
                break;
            case 12:
                printf("Creating List 2\n");
                while (1) {
                    printf("Enter data for List 2 (0 to stop): ");
                    scanf("%d", &data);
                    if (data == 0) {
                        break;
                    }
                    insertAtEnd(&list2, data);
                }
                traverse(list2);
                break;
            case 13:
                {
                    struct Node* unionResult = unionLists(list1, list2);
                    printf("Union of List 1 and List 2: ");
                    traverse(unionResult);
                }
                
                break;
            case 14:
                {
                    struct Node* intersectionResult = intersection(list1, list2);
                    printf("Intersection of List 1 and List 2: ");
                    traverse(intersectionResult);
                }
                break;
            case 15:
                printf("Number of nodes in the list: %d\n", getCount(list1));
                break;
            case 16:
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
                break;
        }
    }

    // Free memory
    while (list1 != NULL) {
        struct Node* temp = list1;
        list1 = list1->next;
        free(temp);
    }
    while (list2 != NULL) {
        struct Node* temp = list2;
        list2 = list2->next;
        free(temp);
    }

    return 0;
}
