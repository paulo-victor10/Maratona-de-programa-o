#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, menor=100000;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        menor=min(menor,a[i]);
    }
    int ans=0;
    for(auto& x:a){
        ans+=x-menor;
    }
    cout<<ans;

}