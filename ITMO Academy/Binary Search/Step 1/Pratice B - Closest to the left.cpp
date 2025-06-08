#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin>>a[i]; 

    while (k--)
    {
        int x,l=-1,r=n; 
        cin>>x; 
        
        while (l<r-1) 
        {
            int m=(l+r)/2;  
            if (a[m]<=x) l=m; 
            else r=m;
        }
        cout<<l+1<<endl;
    }
}