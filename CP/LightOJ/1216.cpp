#include <bits/stdc++.h>

#define pi (2*acos(0))

using namespace std;

int main()
{
  int T, i=1;
  cin >> T;

  while(i <= T)
  {
    double x, r1, r2, h, p, vol, y;
    cin >> r1 >> r2 >> h >> p;

    y = (h*r2)/(r1 - r2);

    x = r2 + (p*(r1 - r2))/h;

    vol = ((1/3.0)*(pi*pow(x, (double)2)*(p+y))) - ((1/3.0)*pi*pow(r2, (double)2)*y);

    printf("Case %d: %.9lf\n", i, vol);
    i++;
  }

  return 0;
}
