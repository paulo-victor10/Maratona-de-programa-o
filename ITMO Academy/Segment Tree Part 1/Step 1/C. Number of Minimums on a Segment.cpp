//Wrong answer on test 12

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5 + 10;
const int INF = 1e9 + 10;

ll st[4 * N], v[N], st_qtd[4 * N];

void build(int p, int l, int r)
{
    if (l == r)
    {
        st[p] = v[l];
        st_qtd[p] = 1;
        return;
    }
    int m = (l + r) / 2;
    build(2 * p, l, m);
    build(2 * p + 1, m + 1, r);

    st[p] = min(st[2 * p], st[2 * p + 1]); // até aqui normal

    if ((st[2 * p] == st[2 * p + 1]))
    { // se os filhos forem iguais
        if (st[p] == st[2 * p])
            st_qtd[p] = st_qtd[2 * p] + st_qtd[2 * p + 1];
    }

    else if (st[2 * p] == st[p])
    {
        st_qtd[p] = st_qtd[2 * p];
    }
    else if (st[2 * p + 1] == st[p])
    {
        st_qtd[p] = st_qtd[2 * p + 1];
    }
}

int query(int p, int l, int r, int i, int j)
{
    if (r < i or j < l)
        return INF;

    if (i <= l and r <= j)
        return st[p];

    int m = (l + r) / 2;
    int x = query(2 * p, l, m, i, j);
    int y = query(2 * p + 1, m + 1, r, i, j);
    return min(x, y);
}

int query_qtd(int p, int l, int r, int i, int j)
{
    if (r < i or j < l)
        return 0;
    if (i <= l and r <= j)
        return st_qtd[p];
    int x = query_qtd(2 * p, l, (l + r) / 2, i, j);
    int y = query_qtd(2 * p + 1, (l + r) / 2 + 1, r, i, j);

    return x + y;
}

void update(int p, int l, int r, int x, int v)
{
    if (x < l or r < x)
        return;
    if (l == r and l == x)
    {
        st[p] = v;
        st_qtd[p] = 1;
        return;
    }
    int m = (l + r) / 2;
    update(2 * p, l, m, x, v);
    update(2 * p + 1, m + 1, r, x, v);
    st[p] = min(st[2 * p], st[2 * p + 1]); // update no st de min com sucesso

    if (st[2 * p] == st[2 * p + 1])
    { // se os filhos forem iguais
        if (st[p] == st[2 * p])
        {
            st_qtd[p] = st_qtd[2 * p] + st_qtd[2 * p + 1];
        }
    }

    else if (st[2 * p] == st[p])
    {
        st_qtd[p] = st_qtd[2 * p];
    }
    else if (st[2 * p + 1] == st[p])
    {
        st_qtd[p] = st_qtd[2 * p + 1];
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    build(1, 0, n - 1);

    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            ll i, valor;
            cin >> i >> valor;
            update(1, 0, n - 1, i, valor);
        }
        else
        {
            int left, right;
            cin >> left >> right;
            ll ans1 =     query(1, 0, n - 1, left, right - 1);
            ll ans2 = query_qtd(1, 0, n - 1, left, right - 1);
            cout << ans1 << " " << ans2 << "\n";
        }
    }
}