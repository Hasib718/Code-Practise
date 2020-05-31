#include <bits/stdc++.h>

using namespace std;

int divisiblecount(int n)
{
    if (n==0) return 0;

    int ans = (n / 3) * 2;

    if (n % 3 == 2) ans++;

    return ans;
}

int main()
{
  int T, i=1;
  cin >> T;

  while(i <= T)
  {
    int a, b;

    cin >> a >> b;

    printf("Case %d: %d\n", i, divisiblecount(b) - divisiblecount(a-1));
    i++;
  }

  return 0;
}
