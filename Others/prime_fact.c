#include <stdio.h>

#define SZ 100000004

long long int primes[SZ], siv[SZ], cnt;

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
  int a;
  cin >> a;
  


  return 0;
}
