#include <bits/stdc++.h>

using namespace std;

#define SIZE 1005
#define pb push_back
#define INF 100000000

vector<vector<int>> dp(SIZE, vector<int>(SIZE, INF)), bracket(SIZE, vector<int>(SIZE, INF));

void printBracket(int i, int j)
{
    if (i == j) {
        cout << "M" << j;
        return;
    }

    cout << "(";

    printBracket(i, bracket[i][j]);

    printBracket(bracket[i][j]+1, j);

    cout << ")";
}

int main()
{
    int n;
    cin >> n;

    vector<int> chains(n);
    for (int i=0; i<n; i++)
        cin >> chains[i];

    for (int i=1; i<n; i++)
        for (int j=i; j>=1; j--)
            if (i==j) dp[j][i]=0;
            else for (int k=j; k<=i; k++)
                    if (dp[j][k]+dp[k+1][i]+chains[j-1]*chains[k]*chains[i] < dp[j][i])
                        dp[j][i] = dp[j][k]+dp[k+1][i]+chains[j-1]*chains[k]*chains[i], bracket[j][i]=k;


    cout << dp[1][n-1] << endl;

    printBracket(1, n-1);
    cout << endl;

    return 0;
}

/*
4
1 2 3 4

5
40 20 30 10 30

5
10 20 30 40 30

5
50 30 30 20 30

3
10 20 30

5
3 2 4 2 5
*/