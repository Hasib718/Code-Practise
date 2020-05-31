#include <bits/stdc++.h>

using namespace std;

int cnt;
void countOnes (int n)
{
    while (n!=0)
    {
        n = n & (n-1);
        cnt++;
    }
}

int main()
{
  int p, T, i=1;
  cin >> T;

  while(i <= T)
  {
    cin >> p;

    countOnes(p);
    cout << cnt << endl;
  }

  return 0;
}
