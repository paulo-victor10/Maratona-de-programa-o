#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
        vector<pair<int,int>> p;
        while (n--)
        {
            int x,y;
            scanf("%d %d", &x,&y);
            p.push_back(make_pair(x,y));
        }
        sort(p.begin(),p.end(),[](auto& a, auto&b){
            return (a.first<b.first) || (a.first==b.first && a.second>b.second);});

        for(auto& par:p){
            printf("%d %d \n", par.first,par.second);
        }
        
    }
}