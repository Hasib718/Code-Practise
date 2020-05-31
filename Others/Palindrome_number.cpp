#include <bits/stdc++.h>

using namespace std;

int main()
{
  int T, p;
  cin >> T;

  string n="1", m;
  while(T--)
  {
    m=n;
    reverse(m.begin(), m.end());
    if(n==m) cout << m << " ";
    p =
    stoi(n);
    p++;
    n = to_string(p);
  }
}
