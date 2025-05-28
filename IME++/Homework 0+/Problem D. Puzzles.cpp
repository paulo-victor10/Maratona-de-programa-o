#include <bits/stdc++.h>
using ll=long long;
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> f(m);

    for (int i = 0; i < m; i++)
    {
        cin>>f[i];
    }
    sort(f.begin(),f.end());
    int menor=INT_MAX;
    
    for (int i = 0; i <=m-n; i++)
    {
        int dif=f[i+n-1]-f[i];
        menor=min(menor,dif);
    }
    cout<<menor;
}