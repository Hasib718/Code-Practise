#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cin >> n;

  if(n&1) cout << 0 << endl;
  else printf("%d\n", 1 << (n/2));;

  return 0;
}
