#include <bits/stdc++.h>

using namespace std;

#define SIZE 1005

int dp[SIZE][SIZE];

int main()
{
    string x, y;
    cin >> x >> y;

    int lenX = x.length(), lenY = y.length();

    // for finding longest common subsequence
    for (int i=1; i<=lenX; i++)
        for (int j=1; j<=lenY; j++)
            if (x[i-1] == y[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

    cout << dp[lenX][lenY] << endl;

    int lenlcs = dp[lenX][lenY];
    string lcs;

    // for printing longest common subsequence
    while(lenX > 0 and lenY > 0)
        if (x[lenX-1] == y[lenY-1]) lcs += x[lenX-1], lenX--, lenY--;
        else if (dp[lenX-1][lenY] > dp[lenX][lenY-1]) lenX--;
        else lenY--;

    cout << lcs << endl;

    return 0;
}

/**
abaaba
babbab


aggtab
gxtxayb
*/