#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v[i] = make_pair(a, b);
    }
    sort(v.begin(), v.end());

    for(auto& par:v){
        int x=par.first,y=par.second;
        if(k>=x) k+=y;
        else break;
    }
    cout<<k;
}