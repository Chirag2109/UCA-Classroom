#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct Queue {
    int n;
    int front;
    int rear;
    int* q;
} Queue;

Queue* constructor(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->q = (int*)malloc(capacity * sizeof(int));
    queue->n = capacity;
    queue->front = 0;
    queue->rear = 0;
    return queue;
}

void Enqueue(Queue* queue, int x) {
    if (queue->rear == queue->n) {
        printf("Queue is full\n");
        return;
    }
    queue->q[queue->rear++] = x;
}

int Dequeue(Queue* queue) {
    if (queue->front == queue->rear) {
        printf("Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    return queue->q[queue->front++];
}

bool isEmpty(Queue* queue) {
    return queue->front == queue->rear;
}

int size(Queue* queue) {
    return queue->rear - queue->front;
}

void testQueue() {
    Queue* queue = constructor(10);
    Enqueue(queue, 5);
    Enqueue(queue, 11);
    Enqueue(queue, 7);

    assert(size(queue) == 3);
    assert(isEmpty(queue) == false);

    assert(Dequeue(queue) == 5);
    assert(size(queue) == 2);
    assert(isEmpty(queue) == false);

    assert(Dequeue(queue) == 11);
    assert(size(queue) == 1);
    assert(isEmpty(queue) == false);

    Enqueue(queue, 13);
    Enqueue(queue, 19);

    assert(size(queue) == 3);
    assert(isEmpty(queue) == false);

    assert(Dequeue(queue) == 7);
    assert(size(queue) == 2);
    assert(isEmpty(queue) == false);

    free(queue->q);
    free(queue);
}

int main() {
    testQueue();
    printf("All tests passed!\n");
    return 0;
}
