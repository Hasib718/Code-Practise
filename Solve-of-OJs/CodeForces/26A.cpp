#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n+2, 0);
    int ans=0;
    for(int i=2; i<=n; i++)
    {
        if(v[i] == 0)
            for(int j=i; j<=n; j+=i)
                v[j]++;

        if(v[i] == 2) ans++;
    }
    cout << ans << endl;

    return 0;
}