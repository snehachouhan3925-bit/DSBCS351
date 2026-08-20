#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL;
    struct Node *newNode, *temp;
    int k, i;

    // Create first node
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = 10;

    // Create second node
    head->next = (struct Node *)malloc(sizeof(struct Node));
    head->next->data = 20;

    // Create third node
    head->next->next = (struct Node *)malloc(sizeof(struct Node));
    head->next->next->data = 30;
    head->next->next->next = NULL;

    // Position and value
    k = 2;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = 15;

    // Insertion at beginning
    if (k == 1) {
        newNode->next = head;
        head = newNode;
    }
    else {
        temp = head;

        // Move to node before kth position
        for (i = 1; i < k - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            printf("Invalid position\n");
        }
        else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Display
    temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");

    return 0;
}
