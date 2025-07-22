#include <bits/stdc++.h>
using ll=long long;
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> relogio1(n);
    vector<int> relogio2(n);
    for (int i = 0; i < n; i++)
    {
        cin>>relogio1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>relogio2[i];
    }
    sort(relogio1.begin(),relogio1.end());
    sort(relogio2.begin(),relogio2.end());

    vector<int> arcos1(n);
    vector<int> arcos2(n);
    for (int i = 1; i < n; i++)
    {
        arcos1.push_back(abs(abs(relogio1[i]-360000)-abs(relogio1[i-1]-360000)));
        arcos2.push_back(abs(abs(relogio2[i]-360000)-abs(relogio2[i-1]-360000)));
    }
    
    for (int i = 0; i < n; i++)
    {
        if(arcos1[i]!=arcos2[i]) {cout<<"impossible"; return 0;}
    }
    cout<<"possible";
}