#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main(){
    ll n, s; cin >> n >> s; // n = tamanho do vetor, s = valor máximo permitido para a soma do segmento
    vector<ll> a(n);
    for(ll i = 0; i < n; i++) cin >> a[i]; // leitura do vetor

    ll ans = 0, sum = 0, l = 0; // ans = total de segmentos bons, sum = soma atual da janela, l = ponteiro da esquerda

    for (ll r = 0; r < n; r++) // ponteiro r percorre o vetor da esquerda para a direita
    {
        sum += a[r]; // adiciona o elemento atual à soma

        while (sum > s) // se a soma estourar o limite s
        {
            sum -= a[l]; // removemos o elemento da esquerda
            l++; // e avançamos o ponteiro esquerdo
        }

        ans += r - l + 1; 
        // após ajustar a janela, todos os segmentos terminando em r e começando entre l e r (inclusive) são válidos
        // ou seja: [l..r], [l+1..r], ..., [r..r] → total de (r - l + 1) segmentos bons com fim em r
    }

    cout << ans << "\n"; // imprime o total de segmentos bons encontrados
}
