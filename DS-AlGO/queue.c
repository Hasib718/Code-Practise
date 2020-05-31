#include <stdio.h>

#define MAX 10

typedef struct
{
  int data[MAX+1];
  int head, tail;
} queue;

void enqueue(queue *q, int item)
{
  if((q->tail+1) % (MAX+1) == q->head)
  {
    printf("Queue is full\n");
    return;
  }
  q->data[q->tail] = item;
  q->tail = (q->tail+1) % (MAX+1);
}

int dequeue(queue *q)
{
  if(q->tail == q->head)
  {
    printf("Queue is empty\n");
    return -1;
  }
  int item = q->data[q->head];
  q->head = (q->head+1) % (MAX+1);

  return item;
}

int main()
{
  queue my;
  int item;

  my.head=0;
  my.tail=0;

  enqueue(&my, 1);
  enqueue(&my, 2);
  enqueue(&my, 3);
  enqueue(&my, 4);
  enqueue(&my, 5);

  printf("%d\n", dequeue(&my));
  printf("%d\n", dequeue(&my));
  printf("%d\n", dequeue(&my));
  printf("%d\n", dequeue(&my));
}
 
