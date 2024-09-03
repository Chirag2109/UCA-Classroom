#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct C_Queue {
    int front, rear, n, capacity;
    int* cq;
} CircularQueue;

CircularQueue* constructor(int capacity) {
    CircularQueue* q = (CircularQueue*)malloc(sizeof(CircularQueue));
    q->capacity = capacity + 1;
    q->cq = (int*)malloc(q->capacity * sizeof(int));
    q->front = q->rear = 0;
    q->n = 0;
    return q;
}

bool isFull(CircularQueue* q) {
    return (q->n == q->capacity - 1);
}

bool isEmpty(CircularQueue* q) {
    return (q->n == 0);
}

int size(CircularQueue* q) {
    return q->n;
}

void Insert(CircularQueue* q, int x) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->cq[q->rear] = x;
    q->n++;
}

int Delete(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    q->front = (q->front + 1) % q->capacity;
    int item = q->cq[q->front];
    q->n--;
    return item;
}

void testQueue() {
    CircularQueue* q = constructor(10);
    Insert(q, 5);
    Insert(q, 11);
    Insert(q, 7);

    assert(size(q) == 3);
    assert(isEmpty(q) == false);

    assert(Delete(q) == 5);
    assert(size(q) == 2);
    assert(isEmpty(q) == false);

    assert(Delete(q) == 11);
    assert(size(q) == 1);
    assert(isEmpty(q) == false);

    Insert(q, 13);
    Insert(q, 19);

    assert(size(q) == 3);
    assert(isEmpty(q) == false);

    assert(Delete(q) == 7);
    assert(size(q) == 2);
    assert(isEmpty(q) == false);

    free(q->cq);
    free(q);
}

int main() {
    testQueue();
    printf("All tests passed!\n");
    return 0;
}
