#include <bits/stdc++.h>

using namespace std;

#define sz 1005

int n, dp[sz][sz], coins[sz], money;

int main()
{
    cin >> money >> n;

    for (int i = 1; i <= n; ++i)
        cin >> coins[i];

    for (int i = 1; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= money; ++j)
        {
            int way1 = (j >= coins[i]) ? dp[i][j - coins[i]] : 0;

            int way2 = dp[i - 1][j];
            dp[i][j] = way1 + way2;
        }

    cout << dp[n][money] << endl;

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
