#include <bits/stdc++.h>
using ll=long long;
using namespace std;

bool cabe(ll x, ll a, ll b, ll n){
    return (__int128_t)(x/a)*(x/b)>=n; 
}

/*em casos raros mesmo usando ll pode dar overflow em operações matematicas
para evitar isso uso (__int128_t) para aumentar o range de 64 bits para 128 antes da multiplicação
e assim evitar o overflow no pior caso que fica 10^18 bem no limite do long long int
*/

int main(){
    ll n,a,b;
    cin>>a>>b>>n;

    ll l=0, r=max(a,b)*n;

    while (r>l+1)
    {
        ll m=(r+l)/2;
        if (cabe(m,a,b,n)) r=m;
        else l=m;
    }
    cout<<r;
}