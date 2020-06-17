#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    while(n--)
    {
        int t;
        cin >> t;
        
        vector<int> v;
        int a;
        for (int i=0; i<t; i++)
            cin >> a, v.push_back(a);

        int cntOdd=0, cntEven=0;
        for (int i=0; i<t; i++)
            if (i%2 != v[i]%2)
                if (i%2)
                    cntOdd++;
                else
                    cntEven++;

        if (cntEven and cntOdd)
            if (cntEven == cntOdd)
                cout << cntEven << endl;
            else
                cout << "-1" << endl;
        else if (cntEven or cntOdd)
            cout << "-1" << endl;
        else
            cout << "0" << endl;
    }

    return 0;
}