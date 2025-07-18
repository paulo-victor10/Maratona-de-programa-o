#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e4 + 10;

vector<vector<int>> adj(MAX);
int dist[MAX];

void dfs(int v)
{
    for (auto w : adj[v])
    {
        if (dist[w] == -1)
        {
            dist[w] = dist[v] + 1;
            dfs(w);
        }
    }
}

int main()
{
    int n, u, v;
    cin >> n;
    for (int i = 0; i < n-1; i++)
    {
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(dist, -1, sizeof dist);
    dist[0] = 0;
    dfs(0);

    int pos = -1, max_dist = -1;

    for (int i = 0; i < n; i++)
    {
        if (dist[i] > max_dist)
        {
            max_dist = dist[i];
            pos = i;
        }
    }

    memset(dist, -1, sizeof dist);

    dist[pos] = 0;
    dfs(pos);

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans = max(ans, dist[i]);
    }
    cout << ans;
}