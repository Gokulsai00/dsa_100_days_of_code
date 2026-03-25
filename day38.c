#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Deque structure
typedef struct Deque {
    Node* front;
    Node* rear;
    int size;
} Deque;

// Initialize deque
void initDeque(Deque* dq) {
    dq->front = dq->rear = NULL;
    dq->size = 0;
}

// Create new node
Node* createNode(int val) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = val;
    temp->prev = temp->next = NULL;
    return temp;
}

// push_front
void push_front(Deque* dq, int val) {
    Node* temp = createNode(val);

    if (dq->front == NULL) {
        dq->front = dq->rear = temp;
    } else {
        temp->next = dq->front;
        dq->front->prev = temp;
        dq->front = temp;
    }
    dq->size++;
}

// push_back
void push_back(Deque* dq, int val) {
    Node* temp = createNode(val);

    if (dq->rear == NULL) {
        dq->front = dq->rear = temp;
    } else {
        temp->prev = dq->rear;
        dq->rear->next = temp;
        dq->rear = temp;
    }
    dq->size++;
}

// pop_front
void pop_front(Deque* dq) {
    if (dq->front == NULL) return;

    Node* temp = dq->front;
    dq->front = dq->front->next;

    if (dq->front != NULL)
        dq->front->prev = NULL;
    else
        dq->rear = NULL;

    free(temp);
    dq->size--;
}

// pop_back
void pop_back(Deque* dq) {
    if (dq->rear == NULL) return;

    Node* temp = dq->rear;
    dq->rear = dq->rear->prev;

    if (dq->rear != NULL)
        dq->rear->next = NULL;
    else
        dq->front = NULL;

    free(temp);
    dq->size--;
}

// front element
int front(Deque* dq) {
    if (dq->front == NULL) return -1;
    return dq->front->data;
}

// back element
int back(Deque* dq) {
    if (dq->rear == NULL) return -1;
    return dq->rear->data;
}

// empty
int empty(Deque* dq) {
    return dq->size == 0;
}

// size
int size(Deque* dq) {
    return dq->size;
}

// clear
void clear(Deque* dq) {
    while (!empty(dq)) {
        pop_front(dq);
    }
}

// reverse
void reverse(Deque* dq) {
    Node* curr = dq->front;
    Node* temp = NULL;

    while (curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    if (temp != NULL)
        dq->front = temp->prev;

    // swap front & rear
    temp = dq->front;
    dq->front = dq->rear;
    dq->rear = temp;
}

// display
void display(Deque* dq) {
    Node* curr = dq->front;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

// main (demo)
int main() {
    Deque dq;
    initDeque(&dq);

    push_back(&dq, 10);
    push_back(&dq, 20);
    push_front(&dq, 5);
    push_front(&dq, 1);

    display(&dq);  // 1 5 10 20

    pop_front(&dq);
    pop_back(&dq);

    display(&dq);  // 5 10

    printf("Front: %d\n", front(&dq));
    printf("Back: %d\n", back(&dq));
    printf("Size: %d\n", size(&dq));

    reverse(&dq);
    display(&dq);  // 10 5

    clear(&dq);
    printf("Empty: %d\n", empty(&dq));

    return 0;
}