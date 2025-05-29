#include <bits/stdc++.h>
using ll=long long;
using namespace std;

int main()
{
    string s;
    cin>>s;
    ll ans=0;

    for(auto& x:s){
        ans= ans * 26 + (x - 'A' + 1);
    }
    cout<<ans<<endl;
}