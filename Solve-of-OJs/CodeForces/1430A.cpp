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

        int tmp=n, t7=0, tmp1=0, t5=0;
        while(tmp%7 and tmp>=7)
            tmp-=8;
        
        tmp%7 == 0 ? t7 = tmp/7, tmp1=n-tmp, n-=tmp : tmp1=n;

        while(tmp1%5 and tmp1>=5)
            tmp1-=3;

        tmp1%5 == 0 ? t5 = tmp1/5, n-=tmp1 : tmp1=0;

        if (n%3 == 0)
            cout << n/3 << " " << t5 << " " << t7 << endl;
        else cout << "-1" << endl;
    }

    return 0;
}