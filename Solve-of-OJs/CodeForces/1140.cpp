#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a;
    cin >> n;

    vector<int> v;
    for(int i=0; i<n; i++)
        cin >> a, v.push_back(a);

    int ans=0, x=0;
    for(int i=1; i<=n; i++) x = max(x, v[i-1]), (i==x)?ans++:0;

    cout << ans << endl;

    return 0;
}