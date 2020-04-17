#include <bits/stdc++.h>

using namespace std;

void quick_sort(vector<int> &a, int low, int high)
{
  if(low >= high) return;

  bool right = true;
  int begin = low, end = high;

  while(low < high)
  {
    if(a[low] > a[high])
    {
      swap(a[low], a[high]);
      right ^= 1;
    }
    if(right) high--;
    else low++;
  }

  quick_sort(a, begin, low-1);
  quick_sort(a, high+1, end);
}

int main()
{
  int n;
  cin >> n;
  vector<int> v(n);

  for(int i=0; i<n; i++)
    cin >> v[i];

  quick_sort(v, 0, v.size()-1);

  for(auto it = v.begin(); it != v.end(); ++it)
    cout << *it << " ";

  return 0;
}
