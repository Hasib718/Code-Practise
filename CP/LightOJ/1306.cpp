#include <bits/stdc++.h>

using namespace std;

int main()
{
  // clock_t begin, end;
  // double spent_time;
  // begin = clock();
  int n, i=1;
  scanf("%d", &n);

  while(i<=n)
  {
    int A, B, C, x1, x2, y1, y2;

    scanf("%d %d %d %d %d %d %d", &A, &B, &C, &x1, &x2, &y1, &y2);

    int count=0;
    for(int i=x1; i<=x2; i++)
      for(int j=y1; j<=y2; j++)
        if((A*i)+(B*j) == (-C))
          count++;

    printf("Case %d: %d\n", i, count);
    i++;
  }

  // end = clock();
  // spent_time = end - begin;
  // cout << spent_time << endl;

  return 0;
}
