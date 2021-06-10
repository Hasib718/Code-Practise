#include<bits/stdc++.h>

using namespace std;

int main()
{
    int T, i=1;
    cin >> T;

    map<string, int> mp;
    mp["January"]=1;
    mp["February"]=2;
    mp["March"]=3;
    mp["April"]=4;
    mp["May"]=5;
    mp["June"]=6;
    mp["July"]=7;
    mp["August"]=8;
    mp["September"]=9;
    mp["October"]=10;
    mp["November"]=11;
    mp["December"]=12;

    while(i <= T)
    {
        string m1, m2;
        int d1, y1, d2, y2;
        cin >> m1 >> d1;
        getchar();
        cin >> y1;

        cin >> m2 >> d2;
        getchar();
        cin >> y2;

        if(mp[m1] > 2) y1++;
        if(mp[m2]==1 or (mp[m2]==2 and d2 < 29)) y2--;

        printf("Case %d: %d\n", i++ , (y2/4-y2/100+y2/400) - ((y1-1)/4-(y1-1)/100+(y1-1)/400));        
    }

    return 0;
}