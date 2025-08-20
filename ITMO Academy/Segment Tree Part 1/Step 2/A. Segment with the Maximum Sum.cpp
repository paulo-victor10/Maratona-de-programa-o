#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 100010;
const ll INF = 1e9 + 10;

ll st[4 * N][4], v[N];

/*
x[4]={pref, seg, suf, sum}
       0     1    2    3
pref=max(pref1,sum1+pref2)
seg=max(seg1,seg2,suf1+pref2)
suf=max(suf2,sum2+suf1)
sum=sum1+sum2
*/

void build(int p, int l, int r)
{
    ll prefix = st[p][0], seg = st[p][1], sufix = st[p][2], sum = st[p][3];
    if (l == r)
    {
        if (v[l] < 0)
        {
            prefix = 0; // prefix
            seg = 0;    // seg
            sufix = 0;  // sufix
            sum = v[l]; // sum
        }
        else
        {
            prefix = v[l];
            seg = v[l];
            sufix = v[l];
            sum = v[l];
        }
        st[p][0] = prefix;
        st[p][1] = seg;
        st[p][2] = sufix;
        st[p][3] = sum;
        return;
    }
    build(2 * p, l, (l + r) / 2);
    build(2 * p + 1, (l + r) / 2 + 1, r);

    // filho esquerdo:
    ll prefix1 = st[2 * p][0], seg1 = st[2 * p][1], sufix1 = st[2 * p][2], sum1 = st[2 * p][3];
    // filho direito:
    ll prefix2 = st[2 * p + 1][0], seg2 = st[2 * p + 1][1], sufix2 = st[2 * p + 1][2], sum2 = st[2 * p + 1][3];

    prefix = max({prefix1, sum1 + prefix2});
    seg = max({seg1, seg2, sufix1 + prefix2});
    sufix = max({sufix2, sum2 + sufix1});
    sum = sum1 + sum2;
    st[p][0] = prefix;
    st[p][1] = seg;
    st[p][2] = sufix;
    st[p][3] = sum;
}

ll query(int p, int l, int r, int i, int j)
{
    if (r < i or j < l)
        return -INF;
    if (i <= l and r <= j)
        return st[p][1]; // add o valor de seg na resposta

    ll x = query(2 * p, l, (l + r) / 2, i, j);
    ll y = query(2 * p + 1, (l + r) / 2 + 1, r, i, j);

    return max(x, y);
}

void update(int p, int l, int r, ll x, ll v)
{
    if (x < l or r < x)
        return;
    ll prefix = st[p][0], seg = st[p][1], sufix = st[p][2], sum = st[p][3];
    if (l == r and l == x)
    {
        if (v < 0)
        {
            prefix = 0; // prefix
            seg = 0;    // seg
            sufix = 0;  // sufix
            sum = v;    // sum
        }
        else
        {
            prefix = v;
            seg = v;
            sufix = v;
            sum = v;
        }
        st[p][0] = prefix;
        st[p][1] = seg;
        st[p][2] = sufix;
        st[p][3] = sum;
        return;
    }
    update(2 * p, l, (l + r) / 2, x, v);
    update(2 * p + 1, (l + r) / 2 + 1, r, x, v);

    // filho esquerdo:
    ll prefix1 = st[2 * p][0], seg1 = st[2 * p][1], sufix1 = st[2 * p][2], sum1 = st[2 * p][3];
    // filho direito:
    ll prefix2 = st[2 * p + 1][0], seg2 = st[2 * p + 1][1], sufix2 = st[2 * p + 1][2], sum2 = st[2 * p + 1][3];

    prefix = max({prefix1, sum1 + prefix2});
    seg = max({seg1, seg2, sufix1 + prefix2});
    sufix = max({sufix2, sum2 + sufix1});
    sum = sum1 + sum2;
    st[p][0] = prefix;
    st[p][1] = seg;
    st[p][2] = sufix;
    st[p][3] = sum;
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
    cout << query(1, 0, n - 1, 0, n - 1) << "\n";
    //cout<<st[1][1]<<"\n";
    while (m--)
    {
        ll i, v;
        cin >> i >> v;
        update(1, 0, n - 1, i, v);
        cout << query(1, 0, n - 1, 0, n - 1) << "\n";
        //cout<<st[1][1]<<"\n";
    }
}