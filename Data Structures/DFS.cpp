#include <bits/stdc++.h>

#define pb push_back
#define high 8 

using namespace std;

vector<bool>v(high);
vector<int> gph[high];
 
 
void edge(int a, int b)
{
    gph[a].pb(b);
    gph[b].pb(a);
}
 
void DFS(int a)
{
    v[a] = true;
    cout << a << " ";

    for(auto i : gph[a])
        if(!v[(i)])
            DFS((i));
}
 
int main()
{
	int a, b;
	//cin >> high;
    
        for(int j=0; j<12; j++)
        {
            scanf("%d %d", &a, &b);
            edge(a, b);
        }
	
	DFS(0);
 
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

/*

0 1
1 5
1 6
2 3
2 6
3 7
4 2
5 2
5 4
6 5
6 7
7 3

*/