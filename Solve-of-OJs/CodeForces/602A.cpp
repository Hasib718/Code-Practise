#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    long long int a, Bx=0;
    for(int i=n-1; i>=0; i--)
        cin >> a, Bx+=(a*(long long int)pow(x, i));

    int m, y;
    cin >> m >> y;

    long long int b, By=0;
    for(int i=m-1; i>=0; i--)
        cin >> b, By+=(b*(long long int)pow(y, i));

    if(Bx == By) cout << "=" << endl;
    else if(Bx > By) cout << ">" << endl;
    else cout << "<" << endl;

    return 0;
}