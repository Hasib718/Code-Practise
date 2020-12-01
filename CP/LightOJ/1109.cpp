#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ipair;
vector<ipair> vp(1001);

bool comp(const ipair &p1, const ipair p2)
{
    if(p1.first==p2.first) return p1.second > p2.second;
    return p1.first < p2.first;
}

void answer()
{
    for(int i=1; i<=1000; i++)
        vp[i] = {0, i};

    for(int i=1; i<=1000; i++)
        for(int j=i; j<=1000; j=j+i)
            vp[j].first++;

    sort(vp.begin(), vp.end(), comp);
}

int main()
{
    answer();

    int T, i=1;
    cin >> T;

    while(i <= T)
    {
        int n;
        cin >> n;

        printf("Case %d: %d\n", i++, vp[n].second);
    }

    return 0;
}