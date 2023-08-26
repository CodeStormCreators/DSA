#include <bits/stdc++.h>
using namespace std;

// bfs

class graph1
{ 
public:
    vector<list<int>> adj;
    int N;
    graph1(int n)
    {
        N = n;
        adj.resize(n);
    }
    void add_edge(int x, int y)
    {
        adj[x].push_back(y);
    }
    void bfs(int s)
    {
        vector<bool> visited;
        visited.resize(N, false);
        list<int> queue;

        visited[s] = true;
        queue.push_back(s);

        while (!queue.empty())
        {
            s = queue.front();
            cout << s << " ";
            queue.pop_front();

            for (auto a : adj[s])
            {
                if (!visited[a])
                {
                    queue.push_back(a);
                    visited[a] = true;
                }
            }
        }
    }
};

 // dfs

class graph2
{
public:
    vector<vector<int>> adj;
    void add_edge(int x, int y)
    {
        adj[x][y] = 1;
        adj[y][x] = 1;
    }
    void dfs(int a,vector<bool>vis)
    {
        vis[a]=true;
        cout<<a<<" ";
        for(int i=0;i<adj[a].size();i++){
            if(adj[a][i]==1 && (!vis[i])){
                dfs(i,vis);
            }
        }
    }
};

int main()
{
    int v, e, a, b, ch, ch1;
    cout << "No. of edges : ";
    cin >> e;
    cout << "No. of vertices : ";
    cin >> v;

    graph1 o1(v);
    graph2 o2;

    cout << "Enter your choice : ";
    cin >> ch1;

    switch (ch1)
    {
    case 1:
        for (int i = 0; i < e; i++)
        {
            cout << "Enter edge : ";
            cin >> a >> b;
            o1.add_edge(a, b);
        }
        cout << "From which vertex you want to start : ";
        cin >> ch;
        o1.bfs(ch);
        break;
    case 2:
        o2.adj = vector<vector<int>>(v, vector<int>(v, 0));

        for (int i = 0; i < e; i++)
        {
            cout << "Enter edge : ";
            cin >> a >> b;
            o2.add_edge(a, b);
        }
        vector<bool>visited(v,false);

        cout<< "From which vertex you want to start : ";
        cin >> ch;
        o2.dfs(ch,visited);
        break;
    
    }
}