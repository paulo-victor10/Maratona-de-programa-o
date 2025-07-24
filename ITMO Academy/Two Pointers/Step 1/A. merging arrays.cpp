#include <bits/stdc++.h>

using namespace std;
using ll=long long;
const long long MAX=1e9+10;

int main(){
    ll n, m; cin>>n>>m;
    vector<ll> a(n+1); vector<ll> b(m+1);

    for (ll i = 0; i < n; i++) cin>>a[i];
    a[n]=MAX;
    for (ll i = 0; i < m; i++) cin>>b[i];
    b[m]=MAX;

    ll i=0,j=0,k=0;
    vector<ll> c(n+m);

    while (i<n || j<m)
    {
        if(a[i]<b[j]){
            c[k]=a[i];
            k++,i++;
        }
        else
        {
            c[k]=b[j];
            k++,j++;
        }
    }
    for(int x:c){
        cout<<x<<" ";
    }
}