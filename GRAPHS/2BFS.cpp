#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfs(int n, vector<int> adj[])
{
    vector<int> bfs;
    queue<int> q;
    q.push(0);
    int vis[n];
    vis[0] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}