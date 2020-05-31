#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <iomanip>

#define pb push_back
#define lmt 100
#define ipair pair<int, int>
using namespace std;

vector<int> parent, rnk;

vector<pair<int, ipair>> edge, result;

void make_set(int v)
{
    parent[v] = v;
    rnk[v] = 0;
}

int find_set(int v)
{
    if(v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);

    if (rnk[a] > rnk[b])
        parent[b] = a;
    else parent[a] = b;

    if(rnk[a] == rnk[b])
        rnk[b]++;
        
}

int main()
{
    int n;
    cin >> n;

    int a, b, w;
    for(int i = 0; i<14; i++)
    {
        cin >> a >> b >> w;
        edge.push_back({w , {a, b}});
    }

    int cost = 0;
    parent.resize(n);
    rnk.resize(n);

    for(int i=0; i<n; i++)
        make_set(i);

    sort(edge.begin(), edge.end());

    for(auto i : edge)
    {
        if(find_set(i.second.first) != find_set(i.second.second))
        {
            cout << i.second.first << " - " << i.second.second << endl;

            cost += i.first;
            //result.pb(*i);
            union_sets(i.second.first, i.second.second);
        }
    }

    cout << "Minimum Cost = " << cost  << endl;

    return 0;
}


/**
 * 
 
9
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7

*
**/