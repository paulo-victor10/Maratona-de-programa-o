#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,pCount=0,mCount=0;
    cin>>n;
    while (n--)
    {
        int t;
        cin>>t;
        if(t==1) pCount++;
        else mCount++;
    }
    int p,m;
    cin>>p>>m;

    if (p<=pCount && m<=mCount) cout<<"S";
    else cout<<"N";
}