#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ll n,m;
    double c, p, resultado;
    cin>>n>>m>>c>>p;

    if (m*p>=c) {
        cout << fixed << setprecision(2) << 0.00;
    }
    else
    {
        resultado=(c-m*p)/(n-m);
        cout << fixed << setprecision(2) << resultado;
    }
}