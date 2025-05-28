#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
     vector<int> f(n); 
     vector<bool> has_gift(n+1, false); //já recebeu
     vector<int> givers; //precisa dar 
     vector<int> receiver; //precisa receber

     for (int i = 0; i < n; i++)
     {
        cin>>f[i];
        if (f[i]!=0)
        {
            has_gift[f[i]]=true;
        } else{
            givers.push_back(i+1);
        }
        
     }

     for (int j = 1; j <=n; ++j)
     {
        /* code */
     }
     

     
}