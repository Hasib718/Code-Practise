#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n, a;
        cin >> n;

        vector<int> v;
        for (int i=0; i<n; i++)
            cin >> a, v.push_back(a);

        if (n == 1)
        {
            cout << "YES" << endl;
            continue;
        }

        sort(v.begin(), v.end());

        bool test = true;
        for (int i=0; i<n-1; i++)
            if (v[i+1] - v[i] > 1)
            {
                cout << "NO" << endl, test = false;
                break;
            }

        if (test)
            cout << "YES" << endl;
    }

    return 0;
}