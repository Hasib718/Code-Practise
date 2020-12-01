#include <bits/stdc++.h>

#define MAX 10
using namespace std;

struct
{
  int top;
  int data[MAX];
} stack;

void push(stack *s, int item)
{
  if(s->top < MAX)
  {
    s->data[s->top] = item;
    s->top = s->top + 1;
  }
  else cout << "Stack is full!" << endl;
}

int pop(stack *s)
{
  int item;
  if(s->top == 0)
  {
    cout << "Stack is empty!" << endl;
    return -1;
  }
  else
  {
    s->top = s->top - 1;
    item = s->data[s->top];
  }

  return item;
}

int main()
{
  stack my_stack;
  int item;

  my_stack.top=0;

  push(&my_stack, 1);
  push(&my_stack, 2);
  push(&my_stack, 3);

  item = pop(&my_stack);
  cout << item << endl;
  item = pop(&my_stack);
  cout << item << endl;
  item = pop(&my_stack);
  cout << item << endl;

  return 0;
}
