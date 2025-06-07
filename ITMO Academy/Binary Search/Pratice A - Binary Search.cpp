#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    while (k--)
    {
        int x,l=0,r=n-1;
        cin>>x;

        while (l<=r)
        {
            int m=(l+r)/2;
            if (a[m]==x)
            {
                cout<<"YES\n";
                break;
            }
            else if(a[m]<x) l=m+1;
            else r=m-1;
        }   
        cout<<"NO\n";
    }
}