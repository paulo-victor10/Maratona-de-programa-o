#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 100000 + 10;
ll st[4 * N], v[N];

void build(ll p, ll l, ll r)
{
    if (l == r)
    {
        st[p] = v[l];
        return;
    }
    ll mid = (l + r) / 2;
    build(2 * p, l, mid);
    build(2 * p + 1, mid + 1, r);
    st[p] = st[2 * p] + st[2 * p + 1];
}

ll query(ll p, ll l, ll r, ll i, ll j)
{
    if (r < i or j < l)
        return 0;

    if (i <= l and r <= j)
        return st[p];
    ll mid = (l + r) / 2;
    ll x = query(2 * p, l, mid, i, j);
    ll y = query(2 * p + 1, mid + 1, r, i, j);
    return x + y;
}

void update(ll p, ll l, ll r, ll x, ll val)
{
    if (x < l or r < x)
        return;
    if (l == r and l == x)
    {
        st[p] = val;
        return;
    }
    ll mid = (l + r) / 2;
    update(2 * p, l, mid, x, val);
    update(2 * p + 1, mid + 1, r, x, val);
    st[p] = st[2 * p] + st[2 * p + 1];
}

int main()
{
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    build(1, 0, n - 1);
    while (m--)
    {
        ll op;
        cin >> op;
        if (op == 1)
        {
            ll i, valor;
            cin >> i >> valor;
            update(1, 0, n - 1, i, valor);
        }
        else
        {
            ll left, right;
            cin >> left >> right;
            ll ans = query(1, 0, n - 1, left, right - 1);
            cout << ans << "\n";
        }
    }
}