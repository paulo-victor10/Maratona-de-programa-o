#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    string g,p; //gabarito e prova
    cin>>g>>p;
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        if (g[i]==p[i])
        {
            ans++;
        }
        
    }

    cout<<ans;
    
}