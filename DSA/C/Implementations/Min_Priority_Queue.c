#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct P_Queue {
    int n;
    int* pq;
} PriorityQueue;

void exch(int* pq, int i, int j) {
    int t = pq[i];
    pq[i] = pq[j];
    pq[j] = t;
}

void sink(PriorityQueue* p, int k) {
    while (2*k <= p->n) {
        int j = 2*k;
        if (j < p->n && p->pq[j] > p->pq[j+1]) j++;
        if (p->pq[k] <= p->pq[j]) break;
        exch(p->pq, k, j);
        k = j;
    }
}

void swim(PriorityQueue* p, int k) {
    while (k > 1 && p->pq[k/2] > p->pq[k]) {
        exch(p->pq, k, k/2);
        k = k/2;
    }
}

PriorityQueue* constructor(int capacity) {
    PriorityQueue* p = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    p->pq = (int*)malloc((capacity + 1) * sizeof(int));
    p->n = 0;
    return p;
}

void Insert(PriorityQueue* p, int x) {
    p->pq[++p->n] = x;
    swim(p, p->n);
}

int Delete(PriorityQueue* p) {
    int min_elem = p->pq[1];
    exch(p->pq, 1, p->n--);
    sink(p, 1);
    return min_elem;
}

bool isEmpty(PriorityQueue* p) {
    return p->n == 0;
}

int size(PriorityQueue* p) {
    return p->n;
}

void testQueue() {
    PriorityQueue* p = constructor(10);
    Insert(p, 5);
    Insert(p, 11);
    Insert(p, 7);

    assert(size(p) == 3);
    assert(isEmpty(p) == false);

    assert(Delete(p) == 5);
    assert(size(p) == 2);
    assert(isEmpty(p) == false);

    assert(Delete(p) == 7);
    assert(size(p) == 1);
    assert(isEmpty(p) == false);

    Insert(p, 13);
    Insert(p, 19);

    assert(size(p) == 3);
    assert(isEmpty(p) == false);

    assert(Delete(p) == 11);
    assert(size(p) == 2);
    assert(isEmpty(p) == false);

    free(p->pq);
    free(p);
}

int main() {
    testQueue();
    printf("All tests passed!\n");
    return 0;
}
