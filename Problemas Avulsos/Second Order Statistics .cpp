#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x, flag=0;
    vector<int> v;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    for (int i = 1; i < n; i++)
    {
        if (v[i]>v[i-1])
        {
            cout<<v[i]<<"\n";
            flag=1;
            break;
        }
    }
    if (flag==0)
    {
        cout<<"NO"<<"\n";
    }

}