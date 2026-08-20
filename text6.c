#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head, *temp, *prev;

    // Create nodes
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = 10;

    head->next = (struct Node *)malloc(sizeof(struct Node));
    head->next->data = 20;

    head->next->next = (struct Node *)malloc(sizeof(struct Node));
    head->next->next->data = 30;
    head->next->next->next = NULL;

    // Deletion from end
    if (head == NULL) {
        printf("List is empty\n");
    }
    else if (head->next == NULL) {
        free(head);
        head = NULL;
    }
    else {
        temp = head;

        // Move temp to the last node
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }

        // Remove last node
        prev->next = NULL;
        free(temp);
    }

    // Display linked list
    temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");

    return 0;
}
