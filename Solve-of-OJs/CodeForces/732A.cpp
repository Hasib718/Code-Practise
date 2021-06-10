#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k, r;
    cin >> k >> r;

    if((k-r)%10 == 0) cout << "1" << endl;
    else
    {
        int cnt=1;
        while(1)
        {
            if((k*cnt)%10 == 0) break;
            else if(((k*cnt)-r)%10 == 0) break;
            cnt++;
        }

        cout << cnt << endl;
    }

    return 0;
}