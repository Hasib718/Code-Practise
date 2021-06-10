#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    cin >> q;

    while(q--)
    {
        int a, b, n, S;
        cin >> a >> b >> n >> S;

        if(S%n <= b and 1ll*a*n+b>=S) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}