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
  int count();
  void pre_enq(int x);
  void enq(int x);
  void nth_enq(int x, int p);
  void deq();
  void post_deq();
  void nth_deq(int x);
  void printsll();
  node* search(int x);
};

sll::sll()
{
  head = tail = NULL;
}

sll::~sll()
{

}

void sll::pre_enq(int x)
{
  node *cur = new node;
  cur->val = x;
  cur->next = head;

  head = cur;
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

void sll::nth_enq(int x, int p)
{
  node *nth_node, *after, *cur = new node;
  nth_node = search(p);

  cur->val = x;
  cur->next = nth_node->next;

  nth_node->next = cur;
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

void sll::post_deq()
{
  node *cur = head, *temp;
  while(cur->next!=NULL)
  {
    temp = cur;
    cur=cur->next;
  }
  delete cur;
  temp->next = NULL;
  tail = temp;
}

void sll::nth_deq(int x)
{
  node *nth_node, *after, *cur=head;
  nth_node = search(x);
  after = nth_node->next;

  while(cur->next!=nth_node)
    cur=cur->next;

  delete nth_node;
  cur->next = after;
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

int sll::count()
{
  node *cur = head;
  int cnt=0;
  while(cur!=NULL)
  {
    cnt++;
    cur = cur->next;
  }
  return cnt;
}

node* sll::search(int x)
{
  node *cur=head, *prev;

  while(cur != NULL)
  {
    if(cur->val == x) return cur;
    cur = cur->next;
  }
  cout << x << " Doesn't Exist in the list" << endl;
  return 0;
}
int main()
{
  sll sl;
sl.enq(1);
sl.enq(2);
sl.enq(3);
sl.printsll();
sl.nth_enq(7, 2);
sl.printsll();

  return 0;
}
// count();
// pre_enq(int x);
// enq(int x);
// nth_enq(int x, int p);
// deq();
// post_deq();
// nth_deq(int x);
// printsll();
// search(int x);
