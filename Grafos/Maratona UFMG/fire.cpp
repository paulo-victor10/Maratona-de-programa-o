#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;
const int INF = 0x3f3f3f3f;
int dist[N][N];
char adj[N][N];
bool vis[N][N];
int n, m;

vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

bool val(pair<int, int> u)
{
    return u.first >= 0 and u.second >= 0 and u.first < n and u.second < m and adj[u.first][u.second] != '#' and !vis[u.first][u.second];
}

void bfs_ms(vector<pair<int, int>> ms)
{
    memset(vis, 0, sizeof vis);
    memset(dist, INF, sizeof dist);
    queue<pair<int, int>> q;
    for (auto s : ms)
    {
        q.push(s);
        vis[s.first][s.second] = 1;
        dist[s.first][s.second] = 0;
    }

    while (!q.empty())
    {
        auto v = q.front();
        q.pop();

        for (auto u : moves)
        {
            u.first += v.first;
            u.second += v.second;
            if (val(u))
            {
                q.push(u);
                vis[u.first][u.second] = 1;
                dist[u.first][u.second] = dist[v.first][v.second] + 1;
            }
        }
    }
}

int bfs(pair<int, int> s)
{
    memset(vis, 0, sizeof vis);
    queue<pair<int, int>> q;
    q.push(s);
    vis[s.first][s.second] = 1;
    dist[s.first][s.second] = 0;

    while (!q.empty())
    {
        auto v = q.front();
        q.pop();

        if (v.first == 0 or v.first == n-1 or v.second == 0 or v.second == m - 1)
            return dist[v.first][v.second] + 1;

        for (auto u : moves)
        {
            u.first += v.first;
            u.second += v.second;
            if (val(u) and dist[v.first][v.second] + 1 < dist[u.first][u.second])
            {
                q.push(u), vis[u.first][u.second] = 1;
                dist[u.first][u.second] = dist[v.first][v.second] + 1;
            }
        }
    }

    return -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> m >> n;
        vector<pair<int, int>> ms; // multi-source
        pair<int, int> s;          // source
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> adj[i][j];
                if (adj[i][j] == '*')
                    ms.push_back({i, j});
                if (adj[i][j] == '@')
                    s = {i, j};
            }
        }

        // bfs_ms(ms) bfs multi-source
        bfs_ms(ms);
        int ans = bfs(s);

        if(ans==-1) cout<<"IMPOSSIBLE\n";
        else cout<<ans<<"\n";
    }
}