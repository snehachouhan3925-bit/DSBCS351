#include <stdio.h>

#define MAX 10

struct Node {
    int data;
    int next;
};

struct Node list[MAX];
int head = -1;
int freeIndex = 0;

void insert(int value) {
    if (freeIndex >= MAX) {
        printf("List is full\n");
        return;
    }

    int newNode = freeIndex++;
    list[newNode].data = value;
    list[newNode].next = -1;

    if (head == -1) {
        head = newNode;
    } else {
        int temp = head;

        while (list[temp].next != -1)
            temp = list[temp].next;

        list[temp].next = newNode;
    }
}

void display() {
    int temp = head;

    while (temp != -1) {
        printf("%d -> ", list[temp].data);
        temp = list[temp].next;
    }

    printf("NULL\n");
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);

    display();

    return 0;
}
