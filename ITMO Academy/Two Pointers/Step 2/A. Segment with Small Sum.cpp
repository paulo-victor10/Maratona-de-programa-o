#include <bits/stdc++.h>
using ll=long long;
using namespace std;

int main(){
    ll n,s; cin>>n>>s; //tam do vetor e limite da soma
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin>>a[i];
    
    ll sum=0,l=0; //soma atual e pointer na ponta esquerda
    ll ans=0; //tamanho final do maior segmento do vetor cuja soma interna dos elementos no max igual a s
    for (ll r = 0; r < n; r++) //o pointer r começa na posição 0 e vai andando para aumentar o segmento 
    {
        sum+=a[r]; 
        while (sum>s) //enquanto a soma atual for maior que o limite da soma
        {
            sum-=a[l]; //movemos o pointer l para diminuir o segmento e consequentemente a soma atual
            l++; //andamos 1 passo com o l
        }
        ll segmento_atual=r-l+1; //tamanho do segmento encontrado nessa iteração
        ans=max(ans,segmento_atual); //o maior segmento (comprimento) será a resposta final
    }

    cout<<ans<<"\n";
}