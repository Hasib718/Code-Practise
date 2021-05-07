#include <bits/stdc++.h>

using namespace std;

int n, limit;
vector<int> weight, profit;

int knapSack(int W, int n)
{
    int dp[n+1][W+1];

    for (int i = 0; i <= n; i++)
        for (int w = 0; w <= W; w++)
            if (i == 0 or w == 0)
                dp[i][w] = 0;
            else if (weight[i - 1] <= W)
                if (w - weight[i - 1] < 0)
                    dp[i][w] = max(dp[i - 1][w], 0);
                else
                    dp[i][w] = max(dp[i - 1][w], profit[i - 1] + dp[i - 1][w - weight[i - 1]]);
            else
                dp[i][w] = dp[i - 1][w];

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++) cout << dp[i][w] << " ";

        puts("");
    }   
    return dp[n][W];
}

int main()
{
    int w, p;
    while (scanf("%d %d", &n, &limit) == 2)
    {
        for (int i = 0; i < n; i++)
            cin >> w >> p, weight.push_back(w), profit.push_back(p);

        cout << knapSack(limit, n) << endl;
    }
}

/*
5 10
4 10
1 120
4 280
3 150
4 200
*/

/*
3 50
10 60
20 100
30 120
*/