#include <bits/stdc++.h>

using namespace std;
using ll= long long;
int main()
{
    ll n;
    cin >> n;
    vector<ll> sums(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> sums[i];
    }
    vector<ll> a(n);

    for (ll i = n - 1; i >= 0; i--)
    {
        if (i == 0)
        {
            a[i] = sums[i];
            break;
        }

        a[i] = sums[i] - sums[i - 1];
    }

    for (auto x : a)
    {
        cout << x << " ";
    }
}