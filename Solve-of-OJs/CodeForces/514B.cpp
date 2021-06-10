#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x, y;
    cin >> n >> x >> y;

    set<double> s;
    int a, b;
    for(int i=0; i<n; i++)
        cin >> a >> b, (a-x)==0 ? s.insert(INT_MAX) : s.insert((double)(b-y)/(double)(a-x));

    cout << s.size() << endl;

    return 0;
}