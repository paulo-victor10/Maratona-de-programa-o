#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e4 + 10;
vector<vector<int>> adj(MAX);
vector<bool> vis(MAX, false);
bool temCiclo = false;

void dfs(int v, int pai)
{
    vis[v] = true;

    for (int w : adj[v])
    {
        if (!vis[w])
        {
            dfs(w, v);
        }
        else if (w != pai)
        {
            temCiclo = true;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    if (m != n - 1)
    {
        cout << "NO\n";
        return 0;
    }

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(0, -1);

    bool conexo = true;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            conexo = false;
            break;
        }
    }

    if (conexo && !temCiclo)
        cout << "YES\n";
    else
        cout << "NO\n";
}