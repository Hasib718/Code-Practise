#include <bits/stdc++.h>

using namespace std;

int main()
{
  int a, _r;
  cin >> a;
  _r=a;

  int sum=0, x=0;
  while(x!=1)
  {
    while(a!=0)
    {
      sum += (a%10);
      a/=10;
    }
    if(sum%4==0)
    {
      cout << _r << endl;
      x=1;
    }
    else _r++;
    a=_r;
    sum=0;
  }

  return 0;
}
