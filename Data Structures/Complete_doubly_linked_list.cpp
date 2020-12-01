#include <bits/stdc++.h>

using namespace std;

namespace linked_list
{
template<class T>
class node
{
public:
  T val;
  node<T> *next;
  node<T> *prev;

  node(){}
  node(T x)
  {
    val = x;
    prev = next = NULL;
  }
};

template<class T>
class dll
{
private:
  node<T> *head, *tail;

public:
  dll();
  ~dll();
  int count();
  void pre_enq(T x);
  void post_enq(T x);
  void nth_post_enq(T x, T p);
  void nth_pre_enq(T x, T p);
  void pre_deq();
  void post_deq();
  void nth_deq(T x);
  void printdll_head_to_tail();
  void printdll_tail_to_head();
  node<T>* search(T x);
  void inertion_sort();
};

template<class T>
dll<T>::dll()
{
  head = tail = NULL;
  cout << "You have created me!" << endl;
}

template<class T>
dll<T>::~dll()
{
  cout << "You just killed me!" << endl;
}

template<class T>
void dll<T>::pre_enq(T x)
{
  node<T> *cur = new node<T>(x);

  if(head == NULL && tail == NULL)
  {
    head = tail = cur;
    return;
  }
  cur->next = head;
  head->prev = cur;
  head = cur;
}

template<class T>
void dll<T>::post_enq(T x)
{
  node<T> *cur = new node<T>(x);

  if(head == NULL && tail == NULL)
  {
    head = tail = cur;
    return;
  }
  cur->prev = tail;
  tail->next = cur;
  tail = cur;
}

template<class T>
void dll<T>::nth_post_enq(T x, T p)
{
  node<T> *nth_node, *after, *cur = new node<T>(x);
  nth_node = search(p);
  after = nth_node->next;

  cur->next = nth_node->next;
  cur->prev = nth_node;

  nth_node->next = cur;
  after->prev = cur;
}

template<class T>
void dll<T>::nth_pre_enq(T x, T p)
{
  node<T> *nth_node, *before, *cur = new node<T>(x);
  nth_node = search(p);
  before = nth_node->prev;

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

template<class T>
void dll<T>::pre_deq()
{
  if(head == NULL && tail == NULL)
  {
    cout << "Underflow" << endl;
    return;
  }
  node<T> *cur = head;
  if(head == tail)
    head = tail = NULL;
  else
  {
    head = head->next;
    head->prev = NULL;
  }
  delete cur;
}

template<class T>
void dll<T>::post_deq()
{
  node<T> *cur = tail;
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

template<class T>
void dll<T>::nth_deq(T x)
{
  node<T> *nth_node, *after, *before;
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

template<class T>
void dll<T>::printdll_head_to_tail()
{
  node<T> *cur = head;
  while(cur!=NULL)
  {
    cout << cur->val << " ";
    cur  = cur->next;
  }
  cout << endl;
}

template<class T>
void dll<T>::printdll_tail_to_head()
{
  node<T> *cur = tail;
  while(cur!=NULL)
  {
    cout << cur->val << " ";
    cur  = cur->prev;
  }
  cout << endl;
}

template<class T>
int dll<T>::count()
{
  node<T> *cur = head;
  int cnt=0;
  while(cur!=NULL)
  {
    cnt++;
    cur = cur->next;
  }
  return cnt;
}

template<class T>
node<T>* dll<T>::search(T x)
{
  node<T> *cur=head, *prev;

  while(cur != NULL)
  {
    if(cur->val == x) return cur;
    cur = cur->next;
  }
  cout << x << " Doesn't Exist in the list" << endl;
  return 0;
}

template<class T>
void dll<T>::inertion_sort()
{
  node<T> *cur, *temp=head, *cur_temp=head->next;
  T item;
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

}
int main()
{
  linked_list::dll<char> dl;  dl.printdll_head_to_tail();
  // dl.pre_enq('r');   dl.printdll_head_to_tail();
  // dl.pre_enq('e');  dl.printdll_head_to_tail();
  // dl.pre_enq('a');  dl.printdll_head_to_tail();
  // dl.pre_enq('i');  dl.printdll_head_to_tail();
  // dl.pre_enq('p');  dl.printdll_head_to_tail();
  //dl.nth_pre_enq(9, 4);  dl.printdll_head_to_tail();
  // dl.nth_deq(4);
  //  dl.printdll_head_to_tail();

  char c;
  for(int i=0; i<5; i++)
  {
    cin >> c;
    dl.post_enq(c);
  }
  dl.inertion_sort();
  dl.printdll_head_to_tail();
  dl.printdll_tail_to_head();


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
