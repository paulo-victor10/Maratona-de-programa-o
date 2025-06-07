#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x,y;
    cin>>x>>y;

    if (x==0 || y==0) 
    {
        cout<<"eixos";
        return 0;
    }
    if (x>0)
    {
        if (y>0) cout<<"Q1";
        else cout<<"Q4";
    }
    else
    {
        if (y>0) cout<<"Q2";
        else cout<<"Q3";
    }
}