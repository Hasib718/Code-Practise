#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        if(s[0]!='2' or s[n-1]!='0') puts("NO");
        else
        {
            for(int i=1; i<n-2; i++)
            {
                if(s[i]=='0' and (s[i-1]==2 or s[i+1]==2))
                    for(int j=i+1; j<n-2; j++)
                    {
                        if(s[j]=='2' and (s[j-1]==0 or s[j+1]==0))
                        {
                            puts("YES");
                            return 0;
                        }
                    }
            }
            puts("NO");
        }
        
    }

    return 0;
}