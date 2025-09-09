#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 1e5 + 10;

ll st[4 * N], v[N];

void build(int p, int l, int r)
{
    if (l == r)
    {
        st[p] = v[l];
        return;
    }
    build(2 * p, l, (l + r) / 2);
    build(2 * p + 1, (l + r) / 2 + 1, r);

    st[p] = max(st[2 * p], st[2 * p + 1]);
}

int query(int p, int l, int r, ll x)
{
    if (l == r)
    {
        if (st[p] >= x)
            return l;
        else
            return -1;
    }
    if (st[2 * p] >= x)
        return query(2 * p, l, (l + r) / 2, x);
    else
        return query(2 * p + 1, (l + r) / 2 + 1, r, x);
}

void update(int p, int l, int r, ll x, ll v)
{
    if (x < l or x > r)
        return;
    if (l == r and l == x)
    {
        st[p] = v;
        return;
    }
    update(2 * p, l, (l + r) / 2, x, v);
    update(2 * p + 1, (l + r) / 2 + 1, r, x, v);

    st[p] = max(st[2 * p], st[2 * p + 1]);
}

/*void printFolhas(int p, int l, int r)
{
    if (l == r)
    {

        cout << st[p] << " ";
        return;
    }
    printSt(2 * p, l, (l + r) / 2);
    printSt(2 * p + 1, (l + r) / 2 + 1, r);
}*/

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> v[i];

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
            ll x;
            cin >> x;
            cout << query(1, 0, n - 1, x) << "\n";
        }
    }
}