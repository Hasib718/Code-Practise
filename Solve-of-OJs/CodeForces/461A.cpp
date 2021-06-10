#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int n, a, sum=0;
    cin >> n;

    vector<int> v;
    for(int i=0; i<n; i++)
        cin >> a, sum+=a, v.push_back(a);

    long long int temp = sum;
    sort(v.begin(), v.end());
    for(int i=0; i<n-1; i++)
        sum+=(v[i]+ (temp-v[i])), temp-=v[i];

    cout << sum << endl;

    return 0;
}