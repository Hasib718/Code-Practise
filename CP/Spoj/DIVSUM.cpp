#include <bits/stdc++.h>

using namespace std;

#define SZ 500005

vector<long long int> primes(SZ, 0), siv(SZ, 0);
long long int cnt;

void sieve()
{
  long long int i, j;
  for(i=3; i<SZ; i+=2)
    if(siv[i]==0)
      for(j=i*i; j<SZ; j+=(i+i))
        siv[j] = 1;

  primes[cnt++] = 2;
  for(i=3; i<SZ; i+=2)
    if(siv[i]==0) primes[cnt++] = i;
}

int main()
{
    sieve();

    int n;
    scanf("%d", &n);

    while(n--)
    {
        int m;
        scanf("%d", &m);

        vector<int> v;
        int cnt=1, i=0, sum=0, ans=1, tmp=m;
        while(m != 1)
        {
          if(m%primes[i] == 0)
            cnt*=primes[i], sum+=cnt, m/=primes[i];
          else ans*=(sum+1), i++, cnt=1, sum=0;

          if(m==1) ans*=(sum+1);
        }

        cout << ans-tmp << endl;
    }

    return 0;
}