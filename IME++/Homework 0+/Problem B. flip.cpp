#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s, ans;
    cin>>s;
    ans.reserve(s.size());
    for(const auto& x:s){
        if(x=='1'){
            ans+='0';
        }
        else ans+='1';
    }
    cout<<ans;
}