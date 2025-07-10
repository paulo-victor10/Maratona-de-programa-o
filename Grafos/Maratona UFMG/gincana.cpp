#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3 + 10;

vector<vector<int>> adj(MAX);
vector<bool> vis(MAX);

void dfs(int v)
{
    vis[v] = true;
    for (auto w : adj[v])
    {
        if (!vis[w])
        {
            dfs(w);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int k = 0; k < m; k++)
    {
        int i, j;
        cin >> i >> j;
        i--, j--;
        adj[i].push_back(j);
        adj[j].push_back(i);
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
            ans++;
        }
    }

    cout << ans;
}