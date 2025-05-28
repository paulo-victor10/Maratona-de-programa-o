#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, b, gold=0;
    vector<ll> a;

    cin>>n;

    for (ll i = 0; i < n; i++)
    {
        cin>>b;
        a.push_back(b);
    }

    sort(a.begin(), a.end());

    for (ll i = n-1, j=1; i>-1; i--, j++)
    {
        if (a[i]>j)
        {
            gold+=a[i]-j;
        }
    }
    
    cout<<gold<<endl;
}