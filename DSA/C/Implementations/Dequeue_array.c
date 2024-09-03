#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct Deque {
    int front;
    int rear;
    int size;
    int capacity;
    int* dq;
} Deque;

Deque* constructor(int capacity) {
    Deque* d = (Deque*)malloc(sizeof(Deque));
    d->dq = (int*)malloc(capacity * sizeof(int));
    d->capacity = capacity;
    d->front = -1;
    d->rear = 0;
    d->size = 0;
    return d;
}

bool isFull(Deque* d) {
    return d->size == d->capacity;
}

bool isEmpty(Deque* d) {
    return d->size == 0;
}

void insertFront(Deque* d, int x) {
    if (isFull(d)) {
        printf("Deque is full\n");
        return;
    }
    if (d->front == -1) {
        d->front = 0;
        d->rear = 0;
    } else if (d->front == 0) {
        d->front = d->capacity - 1;
    } else {
        d->front--;
    }
    d->dq[d->front] = x;
    d->size++;
}

void insertRear(Deque* d, int x) {
    if (isFull(d)) {
        printf("Deque is full\n");
        return;
    }
    if (d->front == -1) {
        d->front = 0;
        d->rear = 0;
    } else if (d->rear == d->capacity - 1) {
        d->rear = 0;
    } else {
        d->rear++;
    }
    d->dq[d->rear] = x;
    d->size++;
}

int deleteFront(Deque* d) {
    if (isEmpty(d)) {
        printf("Deque is empty\n");
        return -1;
    }
    int val = d->dq[d->front];
    if (d->front == d->rear) {
        d->front = -1;
        d->rear = -1;
    } else if (d->front == d->capacity - 1) {
        d->front = 0;
    } else {
        d->front++;
    }
    d->size--;
    return val;
}

int deleteRear(Deque* d) {
    if (isEmpty(d)) {
        printf("Deque is empty\n");
        return -1;
    }
    int val = d->dq[d->rear];
    if (d->front == d->rear) {
        d->front = -1;
        d->rear = -1;
    } else if (d->rear == 0) {
        d->rear = d->capacity - 1;
    } else {
        d->rear--;
    }
    d->size--;
    return val;
}

int getFront(Deque* d) {
    if (isEmpty(d)) {
        printf("Deque is empty\n");
        return -1;
    }
    return d->dq[d->front];
}

int getRear(Deque* d) {
    if (isEmpty(d)) {
        printf("Deque is empty\n");
        return -1;
    }
    return d->dq[d->rear];
}

void testDeque() {
    Deque* d = constructor(10);
    insertRear(d, 5);
    insertRear(d, 11);
    insertFront(d, 7);

    assert(getRear(d) == 11);
    assert(getFront(d) == 7);
    assert(isEmpty(d) == false);

    assert(deleteFront(d) == 7);
    assert(getFront(d) == 5);

    insertFront(d, 13);
    insertRear(d, 19);

    assert(getFront(d) == 13);
    assert(getRear(d) == 19);
    assert(isEmpty(d) == false);

    assert(deleteRear(d) == 19);
    assert(getRear(d) == 11);

    free(d->dq);
    free(d);
}

int main() {
    testDeque();
    printf("All tests passed!\n");
    return 0;
}
