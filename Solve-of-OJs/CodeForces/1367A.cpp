#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    while(n--)
    {
        string str, ans;
        cin >> str;

        ans += str[0];

        int len = str.length();
        for (int i=1; i<len-2; i++)
            if (str[i] == str[i+1])
                ans += str[i], i++;

        ans += str[len-1];

        cout << ans << endl;
    }

    return 0;
}