#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main()
{
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> ans(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        ll b = a[i];
        int pos = i;
        while (true)
        {
            if (b > a[pos])
            {
                ans[i] = pos + 1;
                break;
            }
            b += k;
            pos = (pos + 1) % n;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}