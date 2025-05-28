#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    int t=0;
    cin>>n>>m;
    while (n>0 && m>0)
    {
        if (n==1 && m==1)
        {
            break;
        }
        if (n>m)
        {
            n-=2, m--;
        }
        else
        {
            m-=2, n--;
        }
        t++;
    }
    cout<<t;
    
}