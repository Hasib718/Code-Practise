#include <bits/stdc++.h>

#define pb push_back
#define high 8

using namespace std;


vector<bool>v(high, false);
vector<int> gph[high];
 
 
void edge(int a, int b)
{
    gph[a].pb(b);
    gph[b].pb(a);
}
 
void BFS(int a)
{
    queue<int> q;
 
    v[a] = true;
    q.push(a);
 
    while(!q.empty())
    {
        int tmp = q.front();
        q.pop();

		cout << tmp << " ";
 
        for(auto i = gph[tmp].begin(); i != gph[tmp].end(); i++)
            if(!v[*i])
            {
                q.push(*i);
                v[(*i)] = true;
               
            }
    }

	cout << endl;
}
 
int main()
{
	int a, b;
	//cin >> high;
    
        for(int j=0; j<14; j++)
        {
            scanf("%d %d", &a, &b);
            edge(a, b);
        }
	
	BFS(0);
 
    return 0;
}

/*

0 1
0 7
1 2
1 7
2 3
2 8
2 5
3 4
3 5
4 5
5 6
6 7
6 8
7 8

*/