#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

typedef struct Node {
    int item;
    struct Node* next;
} Node;

typedef struct queue {
    int n;
    Node* front;
    Node* rear;
} Queue;

Queue* constructor() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    q->n = 0;
    return q;
}

bool isEmpty(Queue* q) {
    return q->front == NULL;
}

int size(Queue* q) {
    return q->n;
}

void enqueue(Queue* q, int item) {
    Node* oldRear = q->rear;
    q->rear = (Node*)malloc(sizeof(Node));
    q->rear->item = item;
    q->rear->next = NULL;

    if (isEmpty(q)) {
        q->front = q->rear;
    } else {
        oldRear->next = q->rear;
    }

    q->n++;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) return INT_MIN;

    Node* temp = q->front;
    int item = q->front->item;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    q->n--;
    free(temp);

    return item;
}

void testQueue() {
    Queue* q = constructor();
    enqueue(q, 3);
    enqueue(q, 5);
    enqueue(q, 7);

    assert(size(q) == 3);
    assert(isEmpty(q) == false);
  
    assert(dequeue(q) == 3);
    assert(size(q) == 2);
    assert(isEmpty(q) == false);

    assert(dequeue(q) == 5);
    assert(size(q) == 1);
    assert(isEmpty(q) == false);

    assert(dequeue(q) == 7);
    assert(size(q) == 0);
    assert(isEmpty(q) == true);

    free(q);
}

int main() {
    testQueue();
    printf("All test cases passed!\n");
    return 0;
}
