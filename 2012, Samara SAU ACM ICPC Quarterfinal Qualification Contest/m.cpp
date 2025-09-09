#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 10; // Maximum number of nodes
int dist[N], par[N];
vector<int> adj[N];
queue<int> q;

void bfs(int s)
{
    memset(dist, 63, sizeof(dist));
    dist[s] = 0;
    q.push(s);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : adj[u])
            if (dist[v] > dist[u] + 1)
            {
                par[v] = u;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    for (int i = 0; i < n; i++)
    {
        if(i+1<n) adj[i].push_back(i+1);
    }
    unordered_map<int, int> m;
    for (int i = n-1; i >= 0; i--)
    {
        if(m.count(c[i])) adj[i].push_back(m[c[i]]);
        m[c[i]]=i;
    }
    bfs(0);

    cout<<dist[n-1];
}