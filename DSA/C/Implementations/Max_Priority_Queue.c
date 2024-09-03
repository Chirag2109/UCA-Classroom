#include <stdio.h>
#include <stdlib.h>

typedef struct P_Queue{
    int n;
    int* pq;
} PriorityQueue;

void exch(int* pq, int i, int j) {
    int t = pq[i];
    pq[i] = pq[j];
    pq[j] = t;
}

void sink(int* pq, int n, int k) {
    while (2*k <= n) {
        int j = 2*k;
        if (j < n && pq[j] < pq[j+1]) j++;
        if (pq[k] >= pq[j]) break;
        exch(pq, k, j);
        k = j;
    }
}

void swim(PriorityQueue* p, int k) {
    while (k > 1 && p->pq[k/2] < p->pq[k]) {
        exch(p->pq, k, k/2);
        k = k/2;
    }
}

PriorityQueue* constructor(int capacity) {
    PriorityQueue* p = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    p->pq = (int*)malloc(capacity * sizeof(int));
    p->n = 0;
    return p;
}

void Insert(PriorityQueue* p, int x) {
    p->pq[++p->n] = x;
    swim(p, p->n);
}

int Delete(PriorityQueue* p) {
    int max_elem = p->pq[1];
    exch(p->pq, 1, p->n--);
    sink(p->pq, p->n, 1);
    return max_elem;
}

int isEmpty(PriorityQueue* p) {
    return p->n == 0;
}

int size(PriorityQueue* p) {
    return p->n;
}

int main() {
    PriorityQueue* p = constructor(10);
    Insert(p, 5);
    Insert(p, 11);
    Insert(p, 7);
    printf("Size: %d\n", size(p));
    printf("Deleted element: %d\n", Delete(p));
    printf("Deleted element: %d\n", Delete(p));
    printf("Size: %d\n", size(p));
    Insert(p, 13);
    Insert(p, 19);
    printf("Size: %d\n", size(p));
    printf("Deleted element: %d\n", Delete(p));
    printf("Size: %d\n", size(p));

    return 0;
}
