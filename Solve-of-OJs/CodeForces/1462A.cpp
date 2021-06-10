#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n, a;
        cin >> n;

        vector<int> head, tail;
        int mid;

        (n%2==0) ? mid=n/2 : mid=(n/2)+1;

        for(int i=0; i<n; i++)
            if(i < mid) cin >> a, head.push_back(a);
            else cin >> a, tail.push_back(a);

        reverse(tail.begin(), tail.end());

        int h=0;
        while(h < tail.size())
            cout << head[h] << " " << tail[h] << " ", h++;
        if(mid != tail.size())  cout << head[h] << endl;
        else cout << endl;
    }

    return 0;
}