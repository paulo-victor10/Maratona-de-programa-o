#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main()
{
    ll n, s; cin >> n >> s; // n = tamanho do vetor, s = soma mínima exigida para o segmento ser bom
    vector<ll> a(n); // vetor de entrada com n elementos
    for (ll i = 0; i < n; i++) cin >> a[i]; // leitura do vetor

    ll ans = 0, sum = 0, l = 0; // ans = resposta final (número de segmentos bons)
                               // sum = soma da janela atual [l..r]
                               // l = ponteiro esquerdo da janela

    for (ll r = 0; r < n; r++) // percorre o vetor com o ponteiro direito
    {
        sum += a[r]; // adiciona o elemento atual à soma da janela [l..r]

        while (sum >= s) // enquanto a soma for suficiente para o segmento ser bom
        {
            ans += n - r; // se a soma atual for válida, então todos os segmentos [l..r], [l..r+1], ..., [l..n-1] são bons
                          // há exatamente (n - r) desses segmentos terminando em r ou depois
            sum -= a[l];  // removemos o elemento da esquerda para tentar achar uma nova janela começando em l+1
            l++;          // avançamos o ponteiro esquerdo
        }
    }
    cout << ans; // imprime a quantidade total de segmentos bons
}
