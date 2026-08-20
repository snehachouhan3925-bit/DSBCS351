#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL;
    struct Node *newNode;

    // Create a new node
    newNode = (struct Node *)malloc(sizeof(struct Node));

    // Store data
    newNode->data = 10;

    // New node points to current head
    newNode->next = head;

    // Make new node the head
    head = newNode;

    // Display linked list
    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL");

    return 0;
}
