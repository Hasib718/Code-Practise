#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n+1), l(n+1, 0);
    set<int> s;
    int t;
    for(int i=0; i<n; i++)
        cin >> a[i];

    for(int i=n-1; i>=0; i--)
        s.insert(a[i]);


    // int p;
    // for(int i=0; i<m; i++)
    //     cin >> p, cout << l[p-1] << endl;

    return 0;
}