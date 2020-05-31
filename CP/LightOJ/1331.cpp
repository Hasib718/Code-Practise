#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, i=1;
  double x, y, z, sum, a, b, c;
  scanf("%d", &n);

  while(i<=n)
  {
    scanf("%lf %lf %lf", &x, &y, &z);

    a = x*x*acos(1-(2*y*z)/((x+y)*(x+z)));
    b = y*y*acos(1-(2*x*z)/((y+x)*(y+z)));
    c = z*z*acos(1-(2*y*x)/((z+y)*(x+z)));

    sum = sqrt((x*y*z)*(x+y+z)) - ((a+b+c)/2);

    printf("Case %d: %.10lf\n", i, sum);
    i++;
  }

  return 0;
}
