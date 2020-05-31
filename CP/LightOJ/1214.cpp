#include <bits/stdc++.h>

using namespace std;

int main()
{
  // clock_t begin, end;
  // double t;
  // begin = clock();

  int T, i=1;
  scanf("%d", &T);


  while(i <= T)
  {
    string s;
    long long int p, n=0, q, j, cnt=0;

    cin >> s;
    scanf("%lld", &p);

    q = s.size();

    if(s[0] == '-') j=1;
    else j=0;

    if(p < 0) p *= (-1);

    for(int z = j; z <q; z++)
    {
      n = (s[z] - '0') + n*10;
      n %= p;
    }

    if(n) printf("Case %d: not divisible\n", i);
    else printf("Case %d: divisible\n", i);

    i++;
    n=0;
    cnt=0;
  }

  // end = clock();
  // cout << end - begin << endl;
  return 0;
}
