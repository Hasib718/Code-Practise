#include <bits/stdc++.h>

using namespace std;

struct node
{
  int val;
  node *next;
  node *prev;
};

struct dll
{
  node *head, *tail;
  dll();
  ~dll();
  int count();
  void pre_enq(int x);
  void post_enq(int x);
  void nth_post_enq(int x, int p);
  void nth_pre_enq(int x, int p);
  void pre_deq();
  void post_deq();
  void nth_deq(int x);
  void printdll_head_to_tail();
  void printdll_tail_to_head();
  node* search(int x);
  void inertion_sort();
};

dll::dll()
{
  head = tail = NULL;
}

dll::~dll()
{

}

void dll::pre_enq(int x)
{
  node *cur = new node;
  cur->val = x;
  cur->next = NULL;
  cur->prev = NULL;

  if(head == NULL && tail == NULL)
  {
    head = tail = cur;
    return;
  }
  cur->next = head;
  head->prev = cur;
  head = cur;
}

void dll::post_enq(int x)
{
  node *cur = new node;
  cur->val = x;
  cur->next = NULL;
  cur->prev = NULL;
  if(head == NULL && tail == NULL)
  {
    head = tail = cur;
    return;
  }
  cur->prev = tail;
  tail->next = cur;
  tail = cur;
}

void dll::nth_post_enq(int x, int p)
{
  node *nth_node, *after, *cur = new node;
  nth_node = search(p);
  after = nth_node->next;

  cur->val = x;
  cur->next = nth_node->next;
  cur->prev = nth_node;

  nth_node->next = cur;
  after->prev = cur;
}

void dll::nth_pre_enq(int x, int p)
{
  node *nth_node, *before, *cur = new node;
  nth_node = search(p);
  before = nth_node->prev;

  cur->val = x;
  cur->next = nth_node;
  cur->prev = before;

  if(head == nth_node)
  {
    nth_node->prev = cur;
    cur->prev=NULL;
    head = cur;
    return;
  }
  nth_node->prev = cur;
  before->next = cur;
}

void dll::pre_deq()
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
  {
    head = head->next;
    head->prev = NULL;
  }
  delete cur;
}

void dll::post_deq()
{
  node *cur = tail;
  if(head == NULL && tail == NULL)
  {
    cout << "Underflow" << endl;
    return;
  }

  if(head == tail)
    head = tail = NULL;
  else
  {
    tail = tail->prev;
    tail->next = NULL;
  }
  delete cur;
}

void dll::nth_deq(int x)
{
  node *nth_node, *after, *before;
  nth_node = search(x);
  after = nth_node->next;
  before = nth_node->prev;


  if(head == nth_node)
  {
    head = nth_node->next;
    head->prev = NULL;
    delete nth_node;
    return;
  }
  else if(tail == nth_node)
  {
    tail = nth_node->prev;
    tail->next = NULL;
    delete nth_node;
    return;
  }
  before->next = after;
  after->prev = before;

  delete nth_node;
}

void dll::printdll_head_to_tail()
{
  node *cur = head;
  while(cur!=NULL)
  {
    cout << cur->val << " ";
    cur  = cur->next;
  }
  cout << endl;
}

void dll::printdll_tail_to_head()
{
  node *cur = tail;
  while(cur!=NULL)
  {
    cout << cur->val << " ";
    cur  = cur->prev;
  }
  cout << endl;
}

int dll::count()
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

node* dll::search(int x)
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

void dll::inertion_sort()
{
  node *cur, *temp=head, *cur_temp=head->next;
  int item;
  for(cur = head->next; cur != NULL; cur=cur->next)
  {
    cur_temp = cur;
    temp = cur_temp->prev;
    while(temp!=NULL && temp->val > cur_temp->val)
    {
       item = cur_temp->val;
       nth_deq(cur_temp->val);
       nth_pre_enq(item, temp->val);
       cur_temp = temp->prev;
       temp = cur_temp->prev;
    }
  }
}

int main()
{
  dll dl;
  dl.post_enq(4);
  dl.post_enq(3);
  dl.post_enq(5);
  dl.post_enq(1);
  dl.post_enq(2);
  dl.nth_pre_enq(9, 4);
  // dl.nth_deq(4);
  //  dl.printdll_head_to_tail();
  dl.inertion_sort();
  dl.printdll_head_to_tail();


  return 0;
}
// count();
// pre_enq(int x);
// post_enq(int x);
// nth_pre_enq(int x, int p);
// nth_post_enq(int x, int p);
// pre_deq();
// post_deq();
// nth_deq(int x);
// printdll_head_to_tail();
// printdll_tail_to_head()
// search(int x);
// insertion_sort();
