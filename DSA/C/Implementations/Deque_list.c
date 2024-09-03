#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

typedef struct Node {
    int item;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct dq {
    int n;
    Node* front;
    Node* rear;
} deque;

deque* constructor() {
    deque* dq = (deque*)malloc(sizeof(deque));
    dq->front = NULL;
    dq->rear = NULL;
    dq->n = 0;
    return dq;
}

bool isEmpty(deque* d) {
    return d->front == NULL;
}

int size(deque* d) {
    return d->n;
}

void insertFront(deque* d, int item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->item = item;
    newNode->next = d->front;
    newNode->prev = NULL;

    if (isEmpty(d)) {
        d->rear = newNode;
    } else {
        d->front->prev = newNode;
    }

    d->front = newNode;
    d->n++;
}

void insertRear(deque* d, int item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->item = item;
    newNode->next = NULL;
    newNode->prev = d->rear;

    if (isEmpty(d)) {
        d->front = newNode;
    } else {
        d->rear->next = newNode;
    }

    d->rear = newNode;
    d->n++;
}

int deleteFront(deque* d) {
    if (isEmpty(d)) return INT_MIN;

    Node* temp = d->front;
    int item = temp->item;
    d->front = d->front->next;

    if (d->front == NULL) {
        d->rear = NULL;
    } else {
        d->front->prev = NULL;
    }

    free(temp);
    d->n--;
    return item;
}

int deleteRear(deque* d) {
    if (isEmpty(d)) return INT_MIN;

    Node* temp = d->rear;
    int item = temp->item;
    d->rear = d->rear->prev;

    if (d->rear == NULL) {
        d->front = NULL;
    } else {
        d->rear->next = NULL;
    }

    free(temp);
    d->n--;
    return item;
}

void testDeque() {
    deque* d = constructor();
    insertFront(d, 3);
    insertRear(d, 5);
    insertFront(d, 7);

    assert(size(d) == 3);
    assert(isEmpty(d) == false);

    assert(deleteRear(d) == 5);
    assert(size(d) == 2);
    assert(isEmpty(d) == false);

    assert(deleteFront(d) == 7);
    assert(size(d) == 1);
    assert(isEmpty(d) == false);

    assert(deleteFront(d) == 3);
    assert(size(d) == 0);
    assert(isEmpty(d) == true);

    free(d);
}

int main() {
    testDeque();
    printf("All test cases passed!\n");

    return 0;
}
