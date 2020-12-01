#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    while(c%b and c>0)
        c-=a;

    c>=0? puts("YES") : puts("NO");

    return 0;
}