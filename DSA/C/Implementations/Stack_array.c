#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

typedef struct stk {
  int* array;
  int n;
  int max_size;
} stack;

stack* constructor(int size) {
  stack* stk = (stack*)malloc(sizeof(stack));
  stk->array = (int*)malloc(size * sizeof(int));
  stk->n = 0;
  stk->max_size = 1;
  return stk;
}

void resize_array(stack* s, int new_capacity)
{
  int * new_array = (int *) malloc(sizeof(int)*new_capacity);

  for(int i = 0; i < s->n; i++)
    new_array[i] = s->array[i];

  free(s->array);
  s->array = new_array;
}


void push(stack* s, int item)
{
  if(s->n < s->max_size) {
    if(s->n == 0) s->max_size = 1;
    else s->max_size = 2*s->n;
    resize_array(s, s->max_size);
  }
  s->max_size = 2*s->n;
  s->array[s->n++] = item;
}

int pop(stack* s)
{
  int item = s->array[--(s->n)];
  if (s->n <= s->max_size/4) resize_array(s, s->n/2);
  s->max_size = s->n/2;

  return item;
}

bool isEmpty(stack* s)
{
  return s->n == 0;
}

int size(stack* s)
{
  return s->n;
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

  free(s->array);
  free(s);
}

int main()
{
  testStack();
  return 0;
}
