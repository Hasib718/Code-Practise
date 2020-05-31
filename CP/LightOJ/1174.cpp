#include <bits/stdc++.h>

#define pb push_back
#define high 102

using namespace std;

vector<bool> v(high, false);
list<int> gph[high];
vector<int> time1(high);
vector<int> time2(high);
 
 
void edge(int a, int b)
{
    gph[a].pb(b);
    gph[b].pb(a);
}
 
void BFS(int a, vector<int> &time)
{
    queue<int> q;

    v[a] = true;
    q.push(a);
    time[a] = 0;
 
    while(!q.empty())
    {
        a = q.front();
        q.pop();
 
        for(auto i : gph[a])
            if(!v[i])
            {
                q.push(i);
                v[(i)] = true;
                time[i] = time[a] + 1;
               
            }
    }
}
 
int main()
{
    int T, i=1;
    int a, b;
    int srt, ed;
    cin >> T;

    while(i <= T)
    {
        int n, r;
        cin >> n;
        cin >> r;

        for(int i=0; i<n; i++)
            gph[i].clear();

        fill(time1.begin(), time1.begin()+n, 0);
        fill(time2.begin(), time2.begin()+n, 0);

        for(int i=0; i<r; i++)
        {
            cin >> a >> b;
            edge(a, b);
        }
        cin >> srt >> ed;

        fill(v.begin(), v.begin()+n, false);
        BFS(srt, time1);
        fill(v.begin(), v.begin()+n, false);
        BFS(ed, time2);

        int mx=0;
        for(int i=0; i<n; i++)
            mx = max(mx, time1[i]+time2[i]);

        printf("Case %d: %d\n", i++, mx);
    }

    return 0;
}