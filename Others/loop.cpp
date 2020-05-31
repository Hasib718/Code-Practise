#include <bits/stdc++.h>

using namespace std;

int main()
{
  int i, j;

  for(i=0; i<5; i++)
  {
    for(j=0; j<5; j++)
      if(j>=i) cout << "*";
      else cout << ".";

    puts("");
  }

  return 0;
}
