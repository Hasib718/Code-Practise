#include <bits/stdc++.h>

using namespace std;

class heap
{
  public:
    heap();
    ~heap();
    int left_child(int a);
    int right_child(int a);
    int parent(int a);
    bool is_max_heap(vector<int> &a);
    void max_heapify(vector<int> &heap, int heap_size, int i);
    void build_max_heap(vector<int> &heap);
    void heap_sort(vector<int> &heap);
    void print_heap(vector<int> &heap);
};

heap::heap()
{
  cout << "You have created a HEAP!" << endl;
}
heap::~heap()
{
  cout << "Heap is deleted!" << endl;
}

int heap::left_child(int a)
{
  return (2*a)+1;
}
int heap::right_child(int a)
{
  return (2*a)+2;
}
int heap::parent(int a)
{
  return (a-1)/2;
}

bool heap::is_max_heap(vector<int> &a)
{
  int p;
  for(int i=a.size(); i>0; i--)
  {
    p = parent(i);

    if(a[p] < a[i]) return (false);
  }

  return (true);
}

void heap::max_heapify(vector<int> &heap, int heap_size, int i)
{
  int left_child_index, right_child_index, largest;

  left_child_index = left_child(i);  
  right_child_index = right_child(i);

  if(left_child_index < heap_size && heap[left_child_index] > heap[i]) largest = left_child_index;
  else largest = i;

  if(right_child_index < heap_size && heap[right_child_index] > heap[largest]) largest = right_child_index;

  if(largest != i)
  {
    swap(heap[i], heap[largest]);

    max_heapify(heap, heap_size, largest);
  }
}

void heap::build_max_heap(vector<int> &heap)
{
  for(int i = (heap.size()/2)-1; i>=0; i--)
    max_heapify(heap, heap.size(), i);
}

void heap::heap_sort(vector<int> &heap)
{
  if(!is_max_heap(heap))  build_max_heap(heap);

  for(int i = heap.size()-1; i>0; i--)
  {
    swap(heap[0], heap[i]);

    max_heapify(heap, i, 0);
  }
}

void heap::print_heap(vector<int> &heap)
{
  for(int i=0; i<heap.size(); i++)
    cout << heap[i] << " ";

    cout << endl;
}

int main()
{
  heap HEAP;
  int n;
  vector<int> v;
//  v.push_back(0);

  while(cin >> n) v.push_back(n);

  if(HEAP.is_max_heap(v)) cout << "It's a max heap" << endl;
  else cout << "It isn't a max heap" << endl;

  HEAP.print_heap(v);

  HEAP.build_max_heap(v);

  if(HEAP.is_max_heap(v)) cout << "It's a max heap" << endl;
  else cout << "It isn't a max heap" << endl;

  HEAP.print_heap(v);
  cout << endl;

  HEAP.heap_sort(v);
  HEAP.print_heap(v);

  return 0;
}

// 19 7 12 3 5 17 10 1 2
// 12 7 1 3 10 17 19 2 5
