#include<bits/stdc++.h>

#define MAX 105
#define pb push_back
#define mp make_pair
typedef std::pair<int, int> ipair;

using namespace std;

vector<vector<int>> adj_mat(MAX, vector<int>(MAX, INT32_MAX));
struct Edge {
    int w = INT32_MAX, to = -1;
};

void prim(int n) {
    int total_weight = 0;
    vector<bool> selected(n, false);
    vector<Edge> min_e(n);
    min_e[0].w = 0;

    for (int i=0; i<n; i++) {
        int v = -1;

        for (int j=0; j<n; j++)
            if (!selected[j] && (v==-1 || min_e[j].w < min_e[v].w))
                v = j;

        if (min_e[v].w == INT32_MAX) {
            cout << "No MST!" << endl;
            exit(0);
        }

        selected[v] = true;
        total_weight += min_e[v].w;
        if (min_e[v].to != -1)
            cout << min_e[v].to << " " << v << endl;

        for (int to=0; to<n; to++)
            if (adj_mat[v][to] < min_e[to].w)
                min_e[to] = {adj_mat[v][to], v};
    }

    cout << total_weight << endl;
}

int main()
{
    int n;
    cin >> n;

    for (int i=0; i<14; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj_mat[a][b] = w;
        adj_mat[b][a] = w;
    }

    prim(n);

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

Cost will be 37
*
**/