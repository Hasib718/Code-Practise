#include <bits/stdc++.h>

using namespace std;

int main()
{
  int i=1, T, n, m, p;
  cin >> T;

  while(i <= T)
  {
    cin >> n >> m;

    p = n*m;
    if(p%2==0) printf("Case %d: %d\n", i, p/2);
    else printf("Case %d: %d\n", i, (p/2)+1);
    i++;
  }

  return 0;
}
