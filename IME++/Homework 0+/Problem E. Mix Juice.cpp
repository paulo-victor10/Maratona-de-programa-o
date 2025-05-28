#include <bits/stdc++.h>
using ll=long long;
using namespace std;

int main()
{
    int n,k, ans=0;
    cin>>n>>k;
    vector<int> f(n);
    for (int i = 0; i < n; i++)
    {
        cin>>f[i];
    }
    sort(f.begin(),f.end());

    for (int i = 0; i < k; i++)
    {
        ans+=f[i];
    }
    cout<<ans;
    
}