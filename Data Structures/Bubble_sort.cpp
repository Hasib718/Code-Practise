#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, tmp, p=0;
  cin >> n;
  vector<int> v;

  for(int i=0; i<n; i++)
  {
    cin >> tmp;
    v.push_back(tmp);
  }

  for(int i=0; i<n-1; i++)
  {
    for(int j=0; j<n-i-1; j++)
    {
      if(v[j] > v[j+1])
      {
        swap(v[j], v[j+1]);
        p==1;
      }
        if(p==1) break;
    }
  }

  for(int i=0; i<n; i++)
    cout << v[i] << " ";

  return 0;
}
