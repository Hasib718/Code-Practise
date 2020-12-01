#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, s;
    cin >> n >> s;

    int f, t;
    while(n--)
        cin >> f >> t, s = max(s, f+t);

    cout << s << endl;

    return 0;
}