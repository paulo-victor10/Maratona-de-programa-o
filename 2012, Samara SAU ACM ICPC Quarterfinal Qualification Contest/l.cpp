#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
   Problema (contexto):
   - Recebemos um array `sums` de tamanho n.
   - Esse array representa os prefixos de um array original `a`.
     Exemplo:
       a = [3, 2, 5]
       sums = [3, 5, 10]   (soma prefixada)
   - A tarefa é reconstruir o array original `a`.

   Ideia da solução:
   - O primeiro elemento de `a` é igual ao primeiro elemento de `sums`.
   - Os demais são obtidos pela diferença:
         a[i] = sums[i] - sums[i-1].
   - Complexidade: O(n).
*/

int main() {
    ll n;
    cin >> n;                // tamanho do array
    vector<ll> sums(n);      // vetor de prefixos

    for (ll i = 0; i < n; i++) {
        cin >> sums[i];      // leitura do array de prefixos
    }

    vector<ll> a(n);         // array original

    // reconstruindo de trás pra frente (poderia ser de frente também)
    for (ll i = n - 1; i >= 0; i--) {
        if (i == 0) {               // caso base: primeiro elemento
            a[i] = sums[i];
            break;
        }
        a[i] = sums[i] - sums[i - 1]; // diferença entre prefixos consecutivos
    }

    // saída do array original
    for (auto x : a) {
        cout << x << " ";
    }
}
