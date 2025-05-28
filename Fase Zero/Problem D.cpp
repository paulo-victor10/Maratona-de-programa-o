#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main(){
    int  n;
    string s,t;
    cin>>n>>s>>t;

    unordered_map<char,double> s_mapa;
    unordered_map<char,double> t_mapa;

    for(const auto& x:s){
        if (x=='*')
        {
           s_mapa[x]++;
        }
    }
    for(const auto& x:t){
        if (x=='*')
        {
           t_mapa[x]++;
        }
    }
    double ans=(s_mapa['*']-t_mapa['*'])/s_mapa['*'];
    cout<<setprecision(2)<<fixed;
    cout<<ans;
}