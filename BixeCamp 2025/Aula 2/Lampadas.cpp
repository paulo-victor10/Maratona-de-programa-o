#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int op, a=0,b=0;
    while (n--) 
    {
        cin>>op; 
        if (op==1)
        {
            if (a==0) a=1; 
            else a=0;
        }
        else
        {
            if (a==0) a=1; 
            else a=0;
            if (b==0) b=1; 
            else b=0;
        }
        
    }
    cout<<a<<endl<<b;
}