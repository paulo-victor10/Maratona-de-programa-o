#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    bool ans=true;
    for (int i = 0; i < n-1; i++)
    {
        if (a[i]>=a[i+1])
        {
            ans=false;
            break;
        }
        
    }
    
    cout<<(ans ? "YES":"NO");
    
}