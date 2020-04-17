#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <iomanip>

using namespace std;

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
    int T;
    cin >> T;

    while(T--)
    {
        int n, tmp;
        cin >> n;
        tmp = n;

        sieve();
        vector<long long int> v;
        int k=0;
        while(tmp!=0)
        {
            if(tmp%primes[k]==0)
            {
                v.push_back(primes[k]);
                cout << tmp /= primes[k];
            }
            else k++;
        }
        for(int a : v)
            cout << a << " ";
    }
}