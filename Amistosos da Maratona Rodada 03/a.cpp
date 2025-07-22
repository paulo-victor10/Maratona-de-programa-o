#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll mdc(ll a, ll b) { //3 e 5
    while (b != 0) { 
        ll resto = a % b; //resto=0
        a = b; //a=1
        b = resto; //b=0
    }
    return a;
}

int main() {
    ll n, x;
    cin >> n >> x;

    vector<ll> saltos(n);
    for (int i = 0; i < n; i++) {
        cin >> saltos[i];
    }

    ll y = saltos[0];
    for (int i = 1; i < n; i++) { 
        y = mdc(y, saltos[i]);
    }

    if (x % y == 0)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
