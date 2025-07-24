#include <bits/stdc++.h>

using namespace std;
using ll=long long;
const long long MAX=1e9+10;

int main(){
    ll n, m; cin>>n>>m;
    vector<ll> a(n); vector<ll> b(m);

    for (ll i = 0; i < n; i++) cin>>a[i];
    for (ll i = 0; i < m; i++) cin>>b[i];
    ll i=0,j=0;
    vector<ll> c(n+m);

    while (i<a.size() || j<b.size())
    {
        if((j==b.size()) || (a[i]<b[j] && i<a.size())){
            c[i+j]=a[i];
            i++;
        }       
        else
        {
            c[i+j]=b[j];
            j++;
        }
        
    }

    for(int x:c){
        cout<<x<<" ";
    }
}
    

   