#include <bits/stdc++.h>

using namespace std;

struct node
{
  int val;
  node *next;
};

struct sll
{
  node *head, *tail;
  sll();
  ~sll();
  void enq(int x);
  void deq();
  void printsll();
};

sll::sll()
{
  head = tail = NULL;
}

sll::~sll()
{

}

void sll::enq(int x)
{
  node *cur = new node;
  cur->val = x;
  cur->next = NULL;
  if(head == NULL && tail == NULL)
  {
    head = tail = cur;
    return;
  }
  tail->next = cur;
  tail = cur;
}

void sll::deq()
{
  if(head == NULL && tail == NULL)
  {
    cout << "Underflow" << endl;
    return;
  }
  node *cur = head;
  if(head == tail)
    head = tail = NULL;
  else
    head = head->next;
  delete cur;
  return;
}

void sll::printsll()
{
  node *cur = head;
  while(cur!=NULL)
  {
    cout << cur->val << " ";
    cur  = cur->next;
  }
  cout << endl;
}

int main()
{
  sll sl;
  sl.enq(5); sl.printsll();
  sl.enq(4); sl.printsll();
  sl.deq(); sl.printsll();
  return 0;
}
