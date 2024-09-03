#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

typedef struct Node
{
  int item;
  struct Node* next;
} Node;

typedef struct stk {
  int n;
  Node* arr;
} stack;

stack* constructor() {
  stack* stk = (stack*)malloc(sizeof(stack));
  stk->arr = NULL;
  stk->n = 0;
  return stk;
}


bool isEmpty(stack* s)
{
  return s->arr == NULL;
}

int size(stack* s)
{
  return s->n;
}

void push(stack* s, int item)
{
  Node* oldHead = s->arr;

  s->arr = (struct Node*) malloc(sizeof(struct Node));
  s->arr->item = item;
  s->arr->next = oldHead;
  s->n++;
}

int pop(stack* s)
{
  if(s->arr == NULL) return INT_MIN;

  struct Node* temp = s->arr;
  int item = s->arr->item;
  s->arr = s->arr->next;
  s->n--;
  free(temp);


  return item;
}

void testStack()
{
  stack* s = constructor(10);
  push(s, 3);
  push(s, 5);
  push(s, 7);

  assert(size(s) == 3);
  assert(isEmpty(s) == false);
  
  assert(pop(s) == 7);
  assert(size(s) == 2);
  assert(isEmpty(s) == false);

  assert(pop(s) == 5);
  assert(size(s) == 1);
  assert(isEmpty(s) == false);

  assert(pop(s) == 3);
  assert(size(s) == 0);
  assert(isEmpty(s) == true);
  free(s);
}


int main()
{
  testStack();

  return 0;
}
