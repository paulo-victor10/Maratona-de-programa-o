#include <bits/stdc++.h>
using ll=long long;
using namespace std;

int main()
{
    ll n,cx,cy,r,ans=0;
    cin>>n>>cx>>cy>>r; 
    
    while (n--)
    {
        ll x,y;
        cin>>x>>y; 
        ll dx=x-cx;
        ll dy=y-cy;
        if(dx*dx + dy*dy<=r*r) ans++;
    }
    cout<<ans;
}