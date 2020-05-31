#include <bits/stdc++.h>

using namespace std;

void insertion_sort(vector<int> &v, int n)
{
  int i, j, item;
  for(i=1; i<n; i++)
  {
    item = v[i];

    j=i-1;
    while(j>=0 && v[j] > item)
    {
      v[j+1] = v[j];
      j--;
    }
    v[j+1] = item;
  }
}
int main()
{
  int n, tmp;
  cin >> n;
  vector<int> v;

  for(int i=0; i<n; i++)
  {
    cin >> tmp;
    v.push_back(tmp);
  }
  insertion_sort(v, n);

  for(int i=0; i<n; i++)
    cout << v[i] << " ";

  return 0;
}
