#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    unordered_set<ll> b;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll ans = 0, l = 0, unicos = 0;

    for (ll r = 0; r < n; r++)
    {
        if (!b.count(a[r]))
        {
            unicos++;
            b.insert(a[r]);
        }
        while (unicos > k)
        {
            unicos--;
            b.erase(a[l]);
            ans+=r-l;
            l++;
        }
        cout<<ans<<endl;
    }
    cout << ans;
}