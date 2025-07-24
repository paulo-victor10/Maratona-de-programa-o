#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<ll> b(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    int i = 0, j = 0, count = 0;
    vector<ll> c(m);

    while (j < m)
    {
        while (i < n && a[i] < b[j])
        {
            i++, count++;
        }
        c[j] = count;
        j++;
    }

    for (int x : c)
    {
        cout << x << " ";
    }
}
