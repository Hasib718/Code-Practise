#include <stdio.h>
#include <malloc.h>

typedef struct node1
{
  node1 *prev;
  int val;
  node1 *next;
} node;

node *start;

void print_list()
{
  node *cur;
  cur  = start;
  while(cur != NULL)
  {
    printf("%d ", cur->val);
    cur = cur->next;
  }
  puts("");
}

void insert(int n)
{
  node *cur = (node*)malloc(sizeof(node)), *temp;
  cur->prev = NULL;
  cur->val = n;
  cur->next = NULL;

  if(start == NULL)
  {
    start = cur;
    return;
  }
  temp = start;
  while(temp->next!=NULL) temp = temp->next;
  temp->next = cur;
  cur->prev = temp;
}
void Delete()
{
  node *temp, *temp2=start;
  while(temp2->next != NULL)
  {
    temp = temp2;
    temp2 = temp2->next;
  }
  free(temp->next);
  temp->next = NULL;
  //puts("NULL");
}

int main()
{
  start = NULL;
  insert(5);
  insert(29);
  print_list();
  Delete();
  print_list();
  return 0;
}
