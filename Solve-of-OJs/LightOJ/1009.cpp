#include <bits/stdc++.h>
#define pb push_back
#define high 20005

using namespace std;

enum color {white, red, black};

int v[high];
vector<int> gph[high];
int vam, ly;

void gph_clear()
{
    for(int i=0; i<high; i++)
    {
        gph[i].clear();
    }
}

void edge(int a, int b)
{
    gph[a].pb(b);
    gph[b].pb(a);
}

void BFS(int a)
{
    queue<int> q;

    v[a] = black;
    q.push(a);
    vam++;

    while(!q.empty())
    {
        int tmp = q.front();
        q.pop();

        for(auto i = gph[tmp].begin(); i != gph[tmp].end(); i++)
            if(v[*i] == white)
            {
                q.push(*i);
                if(v[tmp] == black)
                {
                    ly++;
                    v[*i] = red;
                }
                else
                {
                    vam++;
                    v[*i] = black;
                }
                
            }
    }
}

int main()
{
    int T, i=1;
    scanf("%d", &T);

    while(i <= T)
    {
        gph_clear();
        memset(v, 0, sizeof(v));
        
        int n;
        scanf("%d", &n);

        int a, b, ans=0;
        vam = ly = 0;
        for(int j=0; j<n; j++)
        {
            scanf("%d %d", &a, &b);
            edge(a, b);
        }

        for(int j=0; j<high; j++)
        {
            if(!gph[j].empty() and v[j] == white)
            {
                vam = ly = 0;
                BFS(j);

                ans += max(vam, ly);
            }
        }

        printf("Case %d: %d\n", i, ans);
        i++;
    }

//    cout << black << endl;

    return 0;
}