#include <bits/stdc++.h>

using namespace std;

void selection_sort(vector<int> &v, int n)
{
  int i, j, index_min, temp;

  for(i=0; i<n-1; i++)
  {
    index_min=i;

    for(j=i+1; j<n; j++)
      if(v[j] < v[index_min])
        index_min=j;

    if(index_min != i)
      swap(v[i], v[index_min]);
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
 selection_sort(v, n);

  for(int i=0; i<n; i++)
    cout << v[i] << " ";

  return 0;
}
