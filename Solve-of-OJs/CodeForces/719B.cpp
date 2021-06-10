#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int r, b, mn, rev_r, rev_b;
    r = b = rev_r = rev_b = 0;

    for (int i=0; i<s.length(); i++)
        if (i%2==0)
            s[i]=='r' ? rev_b++ : r++;
        else
            s[i]=='b' ? rev_r++ : b++;

    cout << min(max(b, r), max(rev_b, rev_r)) << endl;

            return 0;
}