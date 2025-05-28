#include <bits/stdc++.h>
using ll=long long;
using namespace std;

int main()
{
    string n;
    cin>>n;
    ll ans=0;
    for(auto& c:n){
        ans= (ans + (c -'0'))%9; //se for divisivel por 9 ans vai ficar com 0 no final
    }
    if(ans==0) cout<<"Yes";
    else cout<<"No";
}