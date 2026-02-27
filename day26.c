#include <stdio.h>
#include <stdlib.h>

// Define structure for Doubly Linked List node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

int main() {
    int n;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    // Input number of nodes
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        // Allocate memory dynamically
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);

        newNode->next = NULL;
        newNode->prev = NULL;

        // If list is empty
        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;   // Link next of last node
            newNode->prev = temp;   // Link prev of new node
            temp = newNode;         // Move temp forward
        }
    }

    // Traverse forward and print elements
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}