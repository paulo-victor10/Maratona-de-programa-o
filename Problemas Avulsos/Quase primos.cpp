#include <bits/stdc++.h>

using namespace std;

int main (){
    int k, count=1;
    cin>>k;
    
    for (int i = 1; i<=k/2; i++)
    {
        if (k%i==0)
        {
            count++;
        }
        
    }
    if (count==3)
    {
        cout<<"S";
    }
    else cout<<"N";
    
    
}