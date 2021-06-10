#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    int n;
    cin >> n;

    for (int i=1; i<=n; i++)
    {
        ll a;
        cin >> a;

        ll sqt = ceil(sqrt(a));
        ll div = (sqt*sqt) - a;
        ll divUlta = a - pow(sqt-1, 2);
        ll row=0, col=0;

        if (div < sqt)
            row = div+1, col = sqt;
        else
            row = sqt, col = divUlta;

        if (sqt%2 == 0)
            swap(row, col);

        printf("Case %d: %lld %lld\n", i, row, col);
    }

    return 0;
}