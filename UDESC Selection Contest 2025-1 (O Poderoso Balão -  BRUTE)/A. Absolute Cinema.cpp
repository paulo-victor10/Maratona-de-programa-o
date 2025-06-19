#include <bits/stdc++.h>
using ll=long long;
#define MOD 1000000007
using namespace std;

int main(){
    int n;
    cin>>n;
    ll ans=0;
    multiset<ll> f;

    while (n--)
    {
        ll x;
        cin>>x;
        f.insert(x);
        ll menor= *f.begin(), maior=*f.rbegin();
        ans+= (menor*maior)%MOD;
    }
    cout<<ans;
    
}