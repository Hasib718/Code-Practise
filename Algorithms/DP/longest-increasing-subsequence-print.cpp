#include <bits/stdc++.h>

using namespace std;

#define SIZE 1005
#define pb push_back

int main()
{
    int n, a;
    cin >> n;

    vector<int> v;
    for (int i = 0; i < n; i++)
        cin >> a, v.pb(a);

    vector<vector<int>> lis(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
            if (v[i] > v[j] and lis[i].size() < lis[j].size() + 1)
                lis[i] = lis[j];
        lis[i].pb(v[i]);
    }

    vector<int> mx = lis[0];
    for (vector<int> x : lis)
        if (x.size() > mx.size())
            mx = x;

    for (int x : mx)
        cout << x << " ";
    cout << endl;

    return 0;
}

/*
8
10 22 9 33 21 50 41 60

6
3 2 6 4 5 1
*/