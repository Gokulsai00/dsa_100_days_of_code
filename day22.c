#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int value;

    for(int i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// Function to count nodes
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* current = head;

    while(current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* head = createList(n);

    printf("%d\n", countNodes(head));

    return 0;
}