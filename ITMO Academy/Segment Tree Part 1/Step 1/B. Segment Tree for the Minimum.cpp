#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 100000 + 10;
const int INF = 1e9 + 10;

/**********************************************************************************
 * SEGMENT TREE (QUICK RANGE SUM / RANGE UPDATE)                                   *
 * Description: The segment tree stores subarray answers in a tree-like fashion,   *
 * in such a way we can query and update ranges in O(logN) time.                   *
 * Time complexity: <O(NlogN), O(logN)>                                            *
 * Usage: update(1, 1, n, pos, val), query(1, 1, n, l, r), build(1, 1, n)          *
 * Notation: st: array which stores the segment tree                               *
 *           v: vector being represented in the segment tree                       *
 *           p: node index (NOT to confuse with the array index)                   *
 **********************************************************************************/

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
    // st[p] = st[2*p]+st[2*p+1];
    st[p] = min(st[2 * p], st[2 * p + 1]);
    // st[p] = max(st[2*p], st[2*p+1]);
}

int query(int p, int l, int r, int i, int j)
{
    if (r < i or j < l)
        return INF;
    //    return 0;
    //  return -INF;
    if (i <= l and r <= j)
        return st[p];
    int x = query(2 * p, l, (l + r) / 2, i, j);
    int y = query(2 * p + 1, (l + r) / 2 + 1, r, i, j);
    // return x+y;
    return min(x, y);
    // return max(x, y);
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
    // st[p] = st[2*p] + st[2*p+1];
    st[p] = min(st[2 * p], st[2 * p + 1]);
    // st[p] = max(st[2*p], st[2*p+1]);
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