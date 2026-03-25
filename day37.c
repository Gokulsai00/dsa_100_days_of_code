#include <stdio.h>

#define MAX 1000

int pq[MAX];
int size = 0;

// Insert element
void insert(int x) {
    if (size == MAX) return;  // overflow (ignored here)
    pq[size++] = x;
}

// Find index of minimum element
int getMinIndex() {
    if (size == 0) return -1;

    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Delete (remove min)
int deletePQ() {
    if (size == 0) return -1;

    int minIndex = getMinIndex();
    int minValue = pq[minIndex];

    // Shift elements left
    for (int i = minIndex; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }

    size--;
    return minValue;
}

// Peek (get min)
int peek() {
    if (size == 0) return -1;

    int minIndex = getMinIndex();
    return pq[minIndex];
}

int main() {
    int N;
    scanf("%d", &N);

    char op[10];
    int x;

    for (int i = 0; i < N; i++) {
        scanf("%s", op);

        if (op[0] == 'i') {   // insert
            scanf("%d", &x);
            insert(x);
        }
        else if (op[0] == 'd') {  // delete
            printf("%d\n", deletePQ());
        }
        else if (op[0] == 'p') {  // peek
            printf("%d\n", peek());
        }
    }

    return 0;
}