#include <bits/stdc++.h>
using ll=long long;
using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n,s,r; //5 20 15
        cin>>n>>s>>r;
        
        int maiorDado=s-r; //5
        int resto=r%(n-1); //resto=3
        r-=resto; //r=12
        vector<int> v(n-1,r/(n-1)); //v(4,3); v=[3 3 3 3]
        int limite=min(6,maiorDado);
        for (int i = 0; i < n-1 and resto>0; i++)
        {
            int aux=v[i]+resto; //aux=4
            
            if(aux<=limite){ //4<=5
                v[i]+=resto;//v[1]=4
                resto-=resto; //resto=0
            }
            else 
            {
                resto=resto-limite+v[i]; //resto=3-5+3=1
                v[i]=limite; //v[0]=5
            }       
        }
        v.push_back(maiorDado);
        for (int i = 0; i < n; i++){cout<<v[i]<<" ";}
        cout<<endl;
    }
}