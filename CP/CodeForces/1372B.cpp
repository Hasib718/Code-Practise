#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    while(n--)
    {
        int m, mx=1;
        cin >> m;

        for(int i=2; i*i<=m; i++)
            if(m%i==0) 
            {
                mx=max(mx, m/i);
                break;
            }

        cout << mx << " " << m-mx << endl;
    }

    return 0;
}