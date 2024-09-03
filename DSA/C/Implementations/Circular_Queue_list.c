#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

typedef struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* arr;
} Queue;

Queue* constructor(unsigned capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->arr = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

bool isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

bool isEmpty(Queue* queue) {
    return (queue->size == 0);
}

int size(Queue* queue) {
    return queue->size;
}

void enqueue(Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->arr[queue->rear] = item;
    queue->size = queue->size + 1;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->arr[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

void testQueue() {
    Queue* queue = constructor(10);
    enqueue(queue, 3);
    enqueue(queue, 5);
    enqueue(queue, 7);

    assert(size(queue) == 3);
    assert(isEmpty(queue) == false);

    assert(dequeue(queue) == 3);
    assert(size(queue) == 2);
    assert(isEmpty(queue) == false);

    assert(dequeue(queue) == 5);
    assert(size(queue) == 1);
    assert(isEmpty(queue) == false);

    assert(dequeue(queue) == 7);
    assert(size(queue) == 0);
    assert(isEmpty(queue) == true);

    free(queue->arr);
    free(queue);
}

int main() {
    testQueue();
    printf("All test cases passed!\n");
    return 0;
}
