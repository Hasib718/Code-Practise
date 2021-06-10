#include <bits/stdc++.h>

using namespace std;

#define sz 1005

int n, dp[sz][sz], coins[sz], money;

int main()
{
    cin >> money >> n;

    for (int i = 1; i <= n; ++i)
        cin >> coins[i];

    for (int i = 1; i <= money; i++)
        dp[0][i] = 10000;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= money; ++j)
            dp[i][j] = (coins[i] > j) ? dp[i - 1][j] : min(dp[i - 1][j], 1 + dp[i][j - coins[i]]);

    cout << dp[n][money] << endl;

    vector<int> v;
    int tmp = money;
    for (int i=n; i>=1; i--) {
       if (dp[i][tmp] != dp[i-1][tmp]) {
           v.push_back(coins[i]);
           tmp -= coins[i];
           i++;
       }
    }

    for(int i=0; i<v.size(); i++)
        cout << v[i] << " ";

    cout << endl;

    return 0;
}

/*
10 4
3 8 9 4

10 4
3 8 9 11

50 4
1 2 5 10
*/
