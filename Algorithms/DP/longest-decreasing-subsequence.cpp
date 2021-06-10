#include <bits/stdc++.h>

using namespace std;

#define SIZE 1005
#define pb push_back

int dp[SIZE];

int main()
{
    int n, a;
    cin >> n;

    vector<int> v;
    for (int i = 0; i < n; i++)
        cin >> a, v.pb(a);

    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
            if (v[i] > v[j] and dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
    }

    cout << *max_element(dp, dp + n) << endl;

    return 0;
}

/*
8
10 22 9 33 21 50 41 60

6
3 2 6 4 5 1
*/