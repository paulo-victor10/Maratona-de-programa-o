#include <bits/stdc++.h>
using ll=long long;
using namespace std;

int main(){
    ll n; //2
    cin>>n;
    vector<ll> a(n-1);//a(1)
    for (ll i = 0; i < a.size(); i++) //0<1
    {
        cin>>a[i]; //a[i]=1
    }

    if (n==2)
    {
        if(a[0]==1) cout<<2;
        else cout<<1;
        return 0;
    }
    
    sort(a.begin(),a.end());
    for (ll i = 1; i < a.size(); i++) //0<0
    {
        if ((a[i]-a[i-1])>1)
        {
            cout<<a[i-1]+1;
            return 0;
        }

    }
    cout<<n;
}