#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/**
 * 
 * OBS Foi uma questão que eu tive que aprender muita teoria para poder resolver então achei necessário essa quantidade exagerada de comentários
 * EXPLICAÇÃO DO CÓDIGO E IDEIA COMEÇANDO PELA FUNÇÃO MAIS IMPORTANTE (O CORE DA RESPOSTA)
 * Gera um número palíndromo em binário a partir de uma "metade" e
 * se o comprimento total (em bits) do palíndromo é ímpar ou par.
 *
 * Parâmetros:
 * - m: a metade esquerda do palíndromo (como valor decimal).
 * - impar: indica se o palíndromo terá número de bits ímpar (1) ou par (0).
 *
 * Retorno:
 * - Valor decimal do palíndromo binário completo.
 *
 * Exemplo (m = 5, impar = 1):
 *   m (binário) = 101
 *   removemos o último bit (central) para não duplicar -> 10
 *   espelhamos bits de 10 de trás para frente -> 01
 *   concatenamos: bin = 101 + 01 = 10101
 */
ll gerarPalindromo(ll m, int impar) {
    // Inicializa o resultado com a metade original
    ll pal = m;

    // Se for palíndromo de comprimento ímpar, descartamos o bit menos significativo
    // da metade para não duplicar o bit central.
    if (impar) {
        m >>= 1;  // equivale a m = m / 2, descarta o bit menos significativo
    }

    // Enquanto houver bits na metade (depois de descartar o central, se for impar)
    // nós espelhamos cada bit para a nova posição em 'pal'.
    while (m > 0) {
        // Desloca 'pal' uma posição para a esquerda (faz espaço para novo bit):
        // equivale a multiplicar por 2.
        pal <<= 1;
        
        // (m & 1) extrai o bit menos significativo de m (0 ou 1), e o adiciona em pal:
        pal |= (m & 1);

        // Descarta o bit menos significativo de m para avançar o espelhamento:
        m >>= 1;
    }

    return pal;
}

/**
 * Conta quantos bits são necessários para representar um número 'a' em binário.
 *
 * Exemplo:
 * - a = 13 -> binário 1101 -> bits = 4
 */
ll contarBits(ll a) {
    ll bits = 0;
    while (a > 0) {
        bits++;
        a >>= 1;  // desloca 'a' um bit para a direita, equivalente a dividir por 2
    }
    return bits;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll x;       // Valor de entrada: limite máximo
    cin >> x;

    // 'y' armazenará o maior palíndromo encontrado (inicializa em 1)
    ll y = 1;

    // Calcula quantos bits são necessários para representar x
    ll maxBits = contarBits(x);

    // Para cada possível comprimento de palíndromo (1 até maxBits):
    for (int bits = 1; bits <= maxBits; bits++) {
        // Calcula quantas possibilidades existem para a "metade" do palíndromo:
        // (bits + 1) / 2 é o número de bits na metade (incluindo o central, se for impar).
        ll limite = 1LL << ((bits + 1) / 2);

        // Busca binária para encontrar o maior 'half' que gera palíndromo <= x
        ll left = 1;
        ll right = limite - 1;
        ll best = 0;

        while (left <= right) {
            ll mid = (left + right) >> 1;  // ponto médio da busca

            // Gera o palíndromo para essa metade e paridade de bits
            ll pal = gerarPalindromo(mid, bits % 2);

            if (pal <= x) {
                // Se é válido, guarda como melhor e tenta ir para metades maiores
                best = max(best, pal);
                left = mid + 1;
            } else {
                // Se ultrapassa x, tenta metades menores
                right = mid - 1;
            }
        }

        // Atualiza a resposta global, se este palíndromo for maior
        y = max(y, best);
    }

    cout << y << '\n';
    return 0;
}