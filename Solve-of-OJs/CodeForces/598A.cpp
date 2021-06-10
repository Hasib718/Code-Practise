#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        long long int n;
        cin >> n;

        int pw = log2(n);
        long long int sum = ((n*(n+1))/2);
        cout << sum - 2*((int)pow(2, pw+1) - 1) << endl;
    }

    return 0;
}