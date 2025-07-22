#include <bits/stdc++.h>
using ll=long long;
using namespace std;

set<string> ans;

void intercalar(string s1, string s2, string atual){
    if(s1.empty() && s2.empty()){
        ans.insert(atual);
        return;
    }
    if(!s1.empty()){
        intercalar(s1.substr(1),s2,atual+s1[0]);
    }
    if(!s2.empty()){
        intercalar(s1,s2.substr(1),atual+s2[0]);
    }
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        string s1,s2; cin>>s1>>s2;
        ans.clear();
        intercalar(s1,s2,"");
        for(const string s:ans){
            cout<<s<<"\n";
        }
        cout<<"\n";
    }
    
}