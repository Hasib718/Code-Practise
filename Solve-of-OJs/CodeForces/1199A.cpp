#include <bits/stdc++.h>

typedef std::pair<int, int> ipair;

using namespace std;

int main()
{
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> v(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    priority_queue<int, vector<int>, greater<int>> p;
    priority_queue<ipair, vector<ipair>, greater<ipair>> q;
    int s, z;
    for (int i = 1; i <= n; i++)
    {
        if (i <= x)
            if (i + y >= n)
                s = 1, z = n;
            else
                s = 1, z = i + y;
        else if (i > x && n - i >= y)
            s = i - x, z = i + y;
        else
            s = i - x, z = n;

        for (int j = s; j <= z; j++)
            q.push({v[j], j});

        if (v[i] == q.top().first)
            p.push(i);
        q = priority_queue<ipair, vector<ipair>, greater<ipair>>();
    }

    cout << p.top() << endl;

    return 0;
}