#include <bits/stdc++.h>

using namespace std;

int main()
{
  int T;
  cin >> T;

  int n, s, t;
  while(T--)
  {
    cin >> n >> s >> t;

    if((n==s) && (n==t)) cout << "1" << endl;
    else cout << max((n-s), (n-t))+1 << endl;
  }

  return 0;
}
