#include <bits/stdc++.h>

using namespace std;
using ll=long long;

int main(){
    string s;
    cin>>s;
    //a=97, z=123,
    ll ans=0;

    for(char c:s){
        ans+='z' - c + 1;
    }
    cout<<ans;
}