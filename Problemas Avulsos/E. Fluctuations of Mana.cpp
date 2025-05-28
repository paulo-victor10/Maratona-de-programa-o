#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    
    ll n, a, vida=0, mana=0;
    cin>>n;
    for (ll i = 0; i < n; i++)
    {
        cin>>a;
        vida+=a;
        mana=min(mana,vida);
    }
    if (mana<0)
    {
        mana=(-1)*mana;
    } else mana=0;

    cout<<mana<<endl;
}