#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;

    while (t--)
    {
        string a,b;
        cin>>a>>b;
        if (a[0]==b[0])
        {
            cout<<"YES"<<endl;
            cout<<a.front()<<"*"<<endl;
            
        }
        else if (a.back()==b.back())
        {
            cout<<"YES"<<endl;
            cout<<"*"<<a.back()<<endl;
            
        }
        else
        {
        bool achou=false;

        for (size_t  i = 0; i < a.size()-1 and !achou; i++)
        {
            for (size_t j = 0; j < b.size()-1 and !achou; j++)
            {
                if (a[i]==b[j] and a[i+1]==b[j+1])
                {
                    achou=true;
                    cout<<"YES"<<endl;
                    cout<<"*"<<a[i]<<a[i+1]<<"*"<<endl;
                    break;
                }
                
            } 
        }
        if (!achou) cout<<"NO"<<endl;
        }
    }
}