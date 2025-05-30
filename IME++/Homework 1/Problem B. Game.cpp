#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){cin>>a[i];}
    sort(a.begin(),a.end());
    deque<int> b(a.begin(),a.end());
    
    for (int i = 1; i < n; i++)
    {
        if(i%2!=0) b.pop_back(); 
        else b.pop_front(); 
    }
    for(auto& x:b) cout<<x;
    
}