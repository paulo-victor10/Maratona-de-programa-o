#include <bits/stdc++.h>

using namespace std;

int main(){
    int t,d,m; cin>>t>>d>>m;
    vector<int> meals(m+1);
    
    
    for (int i = 0; i < m; i++)
    {
        cin>>meals[i];
    }
    if(m==0){
        if(d>=t)cout<<"Y"<<"\n";
        else cout<<"N"<<"\n";
        return 0;
    }
    if (meals[0]>=t)
    {
        cout<<"Y"<<"\n";
        return 0;
    }
    
    meals[m]=d;

    for (int i = 1; i <= m; i++)
    {
        if((meals[i]-meals[i-1]) >=t){
            cout<<"Y"<<"\n";
            return 0;
        }
    }
    cout<<"N"<<"\n";
}