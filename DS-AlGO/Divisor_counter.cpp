#include <bits/stdc++.h>

using namespace std;

#define SZ 100000004

long long int siv[SZ];
vector<int> v;

void sieve()
{
  long long int i, j;
  for(i=3; i<SZ; i+=2)
    if(siv[i]==0)
      for(j=i*i; j<SZ; j+=(i+i))
        siv[j] = 1;

  v.push_back(2);
  for(i=3; i<SZ; i+=2)
    if(siv[i]==0) v.push_back(i);
}

int divisor_count(int n)
{
  int l = v.size(), div=1;

  for(int i=0; (i<l) && (v[i]*v[i] <= n); i++)
    if(n%v[i] == 0)
    {
      int count=1;
      while(n%v[i] == 0)
      {
        n /= v[i];
        count++;
      }
      div *= count;
    }
    if(n != 1) div *= 2;
    return div;
}

// int opt_divisor_count(int n)
// {
//   int div = 1;
//   for(int i=2; i*i<=n; i+=2)
//   {
//     if(n%i == 0)
//     {
//       in count =1;
//       while(n%i == 0)
//       n/=i;
//       count++;
//     }
//     div *= count;
//   }
// }

int main()
{
  int n;
  cin >> n;

  for(int i=0; i<10; i++)
    cout << v[i] << " ";
  //cout << divisor_count(n) << endl;
}
