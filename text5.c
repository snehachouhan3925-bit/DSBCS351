#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head, *temp;

    // Create nodes
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = 10;

    head->next = (struct Node *)malloc(sizeof(struct Node));
    head->next->data = 20;

    head->next->next = (struct Node *)malloc(sizeof(struct Node));
    head->next->next->data = 30;
    head->next->next->next = NULL;

    // Deletion from beginning
    if (head == NULL) {
        printf("List is empty\n");
    }
    else {
        temp = head;
        head = head->next;
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
