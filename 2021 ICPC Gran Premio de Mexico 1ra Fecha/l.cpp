#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void printK(ll k)
{
    if (k == 1)
    {
        cout << "2";
        return;
    }

    if (k % 2 == 0)
    {
        cout << "(";
        printK(k / 2);
        cout << ")^2";
    }
    else
    {
        cout << "(2*";
        printK(k - 1);
        cout << ")";
    }
}

int main(){
    int t; cin>>t;
    while (t--)
    {
        ll k; cin>>k;
        printK(k);
        cout<<"\n";
    }
    
}