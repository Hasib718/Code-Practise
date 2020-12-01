#include <bits/stdc++.h>

using namespace std;

int main()
{
    string txt, pat;
    cin >> txt;
    cin >> pat;

    int ans=0;
    int pos=txt.find(pat);
    while(pos != -1) ans++, pos=txt.find(pat, pos+pat.length());

    cout << ans << endl;

    return 0;
}