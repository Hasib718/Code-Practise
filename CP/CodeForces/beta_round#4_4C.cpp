#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, cnt=0;
  cin >> n;
  vector<string> v;
  getchar();

  while(n--)
  {
    string a;
    getline(cin, a);
    v.push_back(a);
  }

  int p=v.size();
  for(int j=p-1; j>=0; j--)
  {
    for(int i=j-1; i>=0; i--)
      if(v[j] == v[i]) cnt++;

    if(cnt != 0)
    {
      string str = to_string(cnt);
      v[j] = v[j] + str;
    }
    else v[j] = "OK";
    cnt = 0;
  }

  for(int i=0; i<v.size(); i++)
    cout << v[i] << endl;

    return 0;
}
