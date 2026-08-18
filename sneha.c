#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

// Insert at the beginning
void insertAtBeginning(struct Node **head, int data) {
    struct Node *newNode = createNode(data);

    newNode->next = *head;
    *head = newNode;
}

// Insert at the end
void insertAtEnd(struct Node **head, int data) {
    struct Node *newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Delete a node by value
void deleteNode(struct Node **head, int data) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = *head;
    struct Node *prev = NULL;

    // If the first node contains the value
    if (temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Search for the node
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found.\n", data);
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Search for a value
int search(struct Node *head, int data) {
    struct Node *temp = head;

    while (temp != NULL) {
        if (temp->data == data) {
            return 1;
        }
        temp = temp->next;
    }

    return 0;
}

// Display the linked list
void display(struct Node *head) {
    struct Node *temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Free the entire list
void freeList(struct Node **head) {
    struct Node *temp;

    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main() {
    struct Node *head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    printf("Original list:\n");
    display(head);

    insertAtBeginning(&head, 5);

    printf("\nAfter inserting 5 at beginning:\n");
    display(head);

    insertAtEnd(&head, 40);

    printf("\nAfter inserting 40 at end:\n");
    display(head);

    deleteNode(&head, 20);

    printf("\nAfter deleting 20:\n");
    display(head);

    if (search(head, 30))
        printf("\n30 is found in the list.\n");
    else
        printf("\n30 is not found in the list.\n");

    freeList(&head);

    return 0;
}
