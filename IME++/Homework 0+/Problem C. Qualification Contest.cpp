#include <bits/stdc++.h>
using ll=long long;
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<string> s;
    for (int i = 0; i < k; i++)
    {
        string x;
        cin>>x;
        s.push_back(x);
    }
    sort(s.begin(),s.end());
    for (int i = 0; i < k; i++)
    {
        cout<<s[i]<<endl;
    }
}