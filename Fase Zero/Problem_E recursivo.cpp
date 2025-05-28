#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
X=1, k=15
X * =2; X=2; K-= 1; K= 14
X * =2; X=4; K-= 1; K= 13
X * =3; X=12; K-= 2; K= 11
X * =5; X=60; K-= 4; K= 7
X * =7; X=420; K-= 6; K= 1

Alcançou o Y == true
agora basta fazer Y*restante dos K (passos que faltam)
e agora voce tem a posição final do X após todos os passos

1 passo restante
X+=Y*K;X=840*/

// vector<ll> fatorar_primos(ll a)
// {
//     vector<ll> fatores;
//     int b = 2;
//     while (a>1)
//     {
//         if (a % b == 0)
//         {
//             fatores.push_back(b);
//             a /= b;
//         }
//         else if (a > 1){b++;}
//     }
//     return fatores;
// }

vector<ll> fatorar_primos(ll a){
    vector<ll> fatores;
    for(ll b=2; b*b<=a;b++){
        while(a%b==0){
            fatores.push_back(b);
            a/=b;
        }
    }
    if(a>1) fatores.push_back(a);
    return fatores;
}

int main()
{
    ll x = 1, y, k, z=1;
    cin >> y >> k; 
    auto f = fatorar_primos(y); 

    if(y==1){
        cout<<1+k;
        return 0;
    }

    for (ll i = 0; k>0 and i<(ll)f.size(); i++)
    {
        x *= f[i];       
        k -= (f[i] - 1); 

        if(k<0){ 
            x+= z * k;
            break;
        }

        if (x == y)
        {
            x += y * k;
            break;
        }
        z*=f[i];
    }
    cout << x;

    return 0;
}