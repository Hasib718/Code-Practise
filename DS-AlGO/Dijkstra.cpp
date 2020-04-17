#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define ipair pair<int, int>

using namespace std;

class Graph
{
    int V;
    list<ipair> *adj_list;
    vector<vector<int>> adj_matrix;

public:
    Graph(int );
    void list_to_mat();
    void addedge(int , int , int );
    void dijkstra(int );
    void BFS(int );
    void DFS(int );
    void recursive_dfs(int , vector<bool> &);
    void parental(vector<int> &, int );
    void floyd_warshall();
    void findpath(vector<vector<int>> & , vector<vector<int>> & , int , int );
//    void kruskal()
    ~Graph();
};

Graph::Graph(int V)
{
    this->V = V;
    adj_list = new list<ipair> [V];
    vector<vector<int>> xp(V, vector<int>(V, INF));
    adj_matrix = xp;
}

Graph::~Graph()
{
    delete adj_list;
}

void Graph::list_to_mat()
{
    for(int i = 0; i<V; i++)
        for(auto j = adj_list[i].begin(); j != adj_list[i].end(); j++)
        {
            int u = (*j).first;
            int v = (*j).second;
            adj_matrix[i][i] = 0;
            if(v == 0) adj_matrix[i][u] = 1;
            else adj_matrix[i][u] = v; 
        }

        for (int i = 0; i < V; i++) { 
        for (int j = 0; j < V; j++){
            if(adj_matrix[i][j] == INF)
                cout << "INF" << " ";
            else 
                cout<< adj_matrix[i][j] << " "; 
        } 
        cout<< "\n"; 
    }
    cout << "\n" << endl;
}

void Graph::addedge(int u, int v, int w)
{
    adj_list[u].push_back(make_pair(v, w));
//    adj_list[v].push_back(make_pair(u, w));
}

void Graph::parental(vector<int> &v, int o)
{
        if(v[o] == -1) return;

        parental(v, v[o]);

        cout << o << " ";
}

void Graph::dijkstra(int src)
{
    priority_queue<ipair, vector<ipair>, greater<ipair>> q;
    vector<int> distance(V, INF);
    vector<int> parent(V);
    parent[src] = -1;
    
    q.push(make_pair(0, src));
    distance[src] = 0;

    vector<bool> visited(V, false);

    while (!q.empty())
    {
        int u = q.top().second;
        q.pop();
        visited[u] = true;

        //list<pair<int, int>>::iterator i;
        for(auto i : adj_list[u])
        {
            int v = i.first;
            int weight = i.second;

            if(!visited[v] and distance[v] > distance[u] + weight)
            {
                distance[v] = distance[u] + weight;
                parent[v] = u;
                q.push(make_pair(distance[v], v));
            }
        }
    }

    printf("Vertex Distance from Source\n");
    for(int i=0; i<V; i++)
    {
        printf("%d -> %d \t\t %d \t\t %d ", src, i, distance[i], src);
        parental(parent, i);
        cout << endl;
    }
}

void Graph::BFS(int a)
{
    queue<int> q;
    vector<bool> visited(V, false);

    q.push(a);
    visited[a] = true;

    cout << "BFS traversal ";
    while(!q.empty())
    {
        int tmp = q.front();
        q.pop();

        cout << tmp << " ";

        for(auto i = adj_list[tmp].begin(); i != adj_list[tmp].end(); i++)
            if(!visited[(*i).first])
            {
                q.push((*i).first);
                visited[(*i).first] = true;
            }
    }
    cout << endl;
}

void Graph::recursive_dfs(int a, vector<bool> &visited)
{
    visited[a] = true;
    cout << a << " ";

    for(auto i = adj_list[a].begin(); i != adj_list[a].end(); i++)
        if(!visited[(*i).first])
            recursive_dfs((*i).first, visited);
}

void Graph::DFS(int a)
{
    vector<bool> visited(V, false);

    cout << "DFS traversal ";
    recursive_dfs(a, visited);
    cout << endl;
}

void Graph::findpath(vector<vector<int>> &v, vector<vector<int>> &y, int i, int j)
{
    if(y[i][j] == INF)
    {
        cout << "INF";
        return;
    }

    cout << i << " ";

    if(i == j) return;

    findpath(v, y, v[i][j], j);
}

void Graph::floyd_warshall()
{
    list_to_mat();

    vector<vector<int>> dist = adj_matrix;
    vector<vector<int>> next(4, vector<int>(4, 0));

    for (int i = 0; i < V; i++)
        for(int j=0; j<V; j++)
            next[i][j] = j;

    for(int k = 0; k<V; k++)
        for(int i = 0; i<V; i++)
            for(int j = 0; j<V; j++)
                if(dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }

    // for (int i = 0; i < V; i++)
    // {
    //     for(int j=0; j<V; j++)
    //         cout << next[i][j] << " ";

    //     cout << endl;
    // }
    // cout <<"\n" << endl;
    for(int i=0; i<V; i++)
    {
        for(int j = 0; j<V; j++)
        {
            if(dist[i][j] == INF)
                cout << "INF" << " ";
            else cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n" << endl;

    for(int i = 0; i<V; i++)
        for(int j = 0; j<V; j++)
        {
            printf("Path from %d to %d :\t", i, j);
            findpath(next, dist, i, j);
            cout << endl;
        }
}

int main()
{
    int V = 9;
    Graph g(V); //must start vertex with 0

    // g.addedge(0, 1, 3);
    // g.addedge(1, 0, 2);
    // g.addedge(1, 2, 2);
    // g.addedge(2, 1, 5);
    // g.addedge(3, 2, 8);
    // g.addedge(3, 0, 20);

	g.addedge(0, 1, 4);
	g.addedge(0, 7, 8);
	g.addedge(1, 2, 8);
	g.addedge(1, 7, 11);
	g.addedge(2, 3, 7);
	g.addedge(2, 8, 2);
	g.addedge(2, 5, 4);
	g.addedge(3, 4, 9);
	g.addedge(3, 5, 14);
	g.addedge(4, 5, 10);
	g.addedge(5, 6, 2);
	g.addedge(6, 7, 1);
	g.addedge(6, 8, 6);
	g.addedge(7, 8, 7);

    g.dijkstra(0);
    // g.dijkstra(0);
    // g.BFS(0);
    // g.DFS(1);

    return 0;
}