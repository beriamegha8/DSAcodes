#include <stdio.h>
#include <stdlib.h>

// Structure for a singly linked list node
struct Node {
    int data;
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
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtStart(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
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
    free(temp);
}

// Function to delete a node from the end of the list
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty, cannot delete from end\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* current = *head;
    struct Node* prev = NULL;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    free(current);
    prev->next = NULL;
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
        free(temp);
        return;
    }
    struct Node* current = *head;
    int currentPosition = 0;
    struct Node* prev = NULL;
    while (current != NULL && currentPosition < position) {
        prev = current;
        current = current->next;
        currentPosition++;
    }
    if (current == NULL) {
        printf("Invalid position for deletion\n");
        return;
    }
    prev->next = current->next;
    free(current);
}

// Function to traverse and print the linked list
void traverse(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to concatenate two linked lists
void concatenate(struct Node** list1, struct Node* list2) {
    if (*list1 == NULL) {
        *list1 = list2;
    } else {
        struct Node* current = *list1;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = list2;
    }
}

// Function to reverse a linked list
void reverse(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
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
int search(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return 1; // Key found
        }
        current = current->next;
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
        if (!search(result, current2->data)) {
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
        if (search(list2, current1->data)) {
            insertAtEnd(&result, current1->data);
        }
        current1 = current1->next;
    }

    return result;
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // Insert nodes into list1
    insertAtEnd(&list1, 1);
    insertAtEnd(&list1, 2);
    insertAtEnd(&list1, 3);

    // Insert nodes into list2
    insertAtEnd(&list2, 3);
    insertAtEnd(&list2, 4);
    insertAtEnd(&list2, 5);

    printf("List 1: ");
    traverse(list1);

    printf("List 2: ");
    traverse(list2);

    // Concatenate lists
    concatenate(&list1, list2);
    printf("Concatenated List: ");
    traverse(list1);

    // Reverse the list
    reverse(&list1);
    printf("Reversed List: ");
    traverse(list1);

    // Sort the list
    sort(&list1);
    printf("Sorted List: ");
    traverse(list1);

    // Prompt the user to enter a key for searching
    int key;
    printf("Enter a key to search: ");
    scanf("%d", &key);

    if (search(list1, key)) {
        printf("Key %d found in the list\n", key);
    } else {
        printf("Key %d not found in the list\n", key);
    }

    // Delete a node from the start
    deleteFromStart(&list1);
    printf("List after deleting from start: ");
    traverse(list1);

    // Delete a node from the end
    deleteFromEnd(&list1);
    printf("List after deleting from end: ");
    traverse(list1);

    // Prompt the user to enter a position for deletion
    int position;
    printf("Enter a position for deletion: ");
    scanf("%d", &position);
    deleteFromPosition(&list1, position);
    printf("List after deleting from position %d: ", position);
    traverse(list1);

    // Insert a node at the start
    int newData;
    printf("Enter data to insert at the start: ");
    scanf("%d", &newData);
    insertAtStart(&list1, newData);
    printf("List after inserting %d at the start: ", newData);
    traverse(list1);

    // Insert a node at the end
    printf("Enter data to insert at the end: ");
    scanf("%d", &newData);
    insertAtEnd(&list1, newData);
    printf("List after inserting %d at the end: ", newData);
    traverse(list1);

    // Prompt the user to enter a position for insertion
    printf("Enter a position for insertion: ");
    scanf("%d", &position);
    printf("Enter data to insert at position %d: ", position);
    scanf("%d", &newData);
    insertAtPosition(&list1, newData, position);
    printf("List after inserting %d at position %d: ", newData, position);
    traverse(list1);

    // Union of lists
    struct Node* unionResult = unionLists(list1, list2);
    printf("Union of List 1 and List 2: ");
    traverse(unionResult);

    // Intersection of lists
    struct Node* intersectionResult = intersection(list1, list2);
    printf("Intersection of List 1 and List 2: ");
    traverse(intersectionResult);

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
    free(unionResult);
    free(intersectionResult);

    return 0;
}


