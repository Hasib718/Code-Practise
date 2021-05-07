#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n+2, 0);
    for(int i=2; i<=n+1; i++)
        if(v[i] == 0)
            for(int j=i*2; j<=n+1; j+=i)
                v[j]=1;

    (n>2) ? puts("2") : puts("1");
    for(int i=2; i<=n+1; i++)
        if(v[i]==0) cout << "1 ";
        else cout << "2 ";
    cout << endl;

    return 0;
}