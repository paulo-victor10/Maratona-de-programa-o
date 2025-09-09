#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int st[4 * N], v[N];

void build(int p, int l, int r)
{
    if (l == r)
    {
        st[p] = v[l];
        return;
    }
    build(2 * p, l, (l + r) / 2);
    build(2 * p + 1, (l + r) / 2 + 1, r);

    st[p] = st[2 * p] + st[2 * p + 1];
}

int query(int p, int l, int r, int k)
{
    if (l == r) //chegou na folha que é a resposta
    {
        return l;
    }
    if (k < st[2 * p]) //a resposta está na esquerda
    {
        return query(2 * p, l, (l + r) / 2, k);
    }

    else //a resposta está na direita
    {
        return query(2 * p + 1, (l + r) / 2 + 1, r, k - st[2 * p]);
    }
}

void update(int p, int l, int r, int x, int v)
{
    if (x < l or r < x)
        return;
    if (l == r and l == x)
    {
        st[p] = v;
        return;
    }

    update(2 * p, l, (l + r) / 2, x, v);
    update(2 * p + 1, (l + r) / 2 + 1, r, x, v);

    st[p] = st[2 * p] + st[2 * p + 1];
}

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
            int i, valor=1;
            cin >> i;
            if(v[i]) valor=0;
            v[i]=valor; 
            update(1, 0, n - 1, i, valor);
        }
        else
        {
            int k;
            cin >> k;
            cout << query(1, 0, n - 1, k) << "\n";
        }
    }
}