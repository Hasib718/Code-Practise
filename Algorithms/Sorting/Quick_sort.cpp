#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &a, int low, int high)
{
  int pivot = a[high];
  int i = low-1;
  for(int j = low; j<high; j++)
  {
    if(a[j] <= pivot)
    {
      i++;
      swap(a[i], a[j]);
    }
  }

  swap(a[i+1], a[high]);
  return (i+1);
}

void quick_sort(vector<int> &a, int low, int high)
{
  if(low <= high)
  {
    int index_pivot = partition(a, low, high);

    quick_sort(a, low, index_pivot-1);
    quick_sort(a, index_pivot+1, high);
  }
}

int main()
{
  int n;
  cin >> n;

  vector<int> v;
  for(int i=0; i<n; i++)
  {
    int t;
    cin >> t;
    v.push_back(t);
  }

  quick_sort(v, 0, n-1);

  for(int j=0; j<n; j++)
    cout << v[j] << " ";

  return 0;
}
