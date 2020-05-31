#include <bits/stdc++.h>

using namespace std;

int main()
{
  int T;
  cin >> T;

  int n, m, tmp;
  int dlt_frnd=0;
  vector<int> v;

  while(T--)
  {
    cin >> n >> m;

    for(int i=0; i<n; i++)
    {
      cin >> tmp;
      v.push_back(tmp);
    }
    while(m--)
    {
      for(int i=0; i<n-1; i++)
      {
        if(v[i] < v[i+1])
        {
          v.erase(v.begin()+i);
          dlt_frnd = 1;
          break;
        }
      }
    }
    if(dlt_frnd==0)
      v.erase(v.end()-1);

      for(auto it = v.begin(); it!=v.end(); ++it)
      {
        cout << *it << " ";
      }
      cout << endl;

    v.clear();
  }

  return 0;
}
