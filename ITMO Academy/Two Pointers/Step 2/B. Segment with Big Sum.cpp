#include <bits/stdc++.h>
using ll=long long;
using namespace std;

const ll INF=1e18;

int main(){
    ll n,s; cin>>n>>s; //tam do vetor e minimo da soma
    vector<ll> a(n); //vetor
    for(ll i=0;i<n;i++) cin>>a[i]; 

    ll sum=0,l=0; //soma do segmento atual e pointer l na ponta esquerda
    ll ans=INF; //resp final inicializada como maior valor possivel porque queremos encontrar o menor segmento (comprimento)
    for (ll r = 0; r < n; r++) //o pointer r começa na posição 0 e vai caminhando para a direita
    {
        sum+=a[r]; //soma do segmento atual +=elemento na posição r
        while (sum - a[l] >= s) //quando sum puder descartar o elemento na posição l sem ficar menor que o minimo da soma que é s
        {
            sum-=a[l]; //decrementa o elemento na posição l para minimizar o comprimento do segmento
            l++; //anda com l
            
        }
        if(sum>=s) ans=min(ans,r-l+1); //se a soma do segmento atual não for menor que s então o comprimento do segmento é uma resposta válida
    }

    cout<< (ans!=INF ? ans:-1) <<"\n"; //se no final o ans não mudar printa -1
}