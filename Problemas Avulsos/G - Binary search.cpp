#include <bits/stdc++.h>
#include <vector>
using namespace std;

int findPos(const vector<int> &v, int targ) {
    int pos = -1;
    int l = 0, r = v.size() - 1;

    // Busca binária
    while (l <= r) {
        int m = (l + r) / 2;
        if (v[m] == targ) {
            pos = m; // Encontrou o elemento
            break;
        } else if (v[m] < targ) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    return pos; // Retorna a posição ou -1 se não encontrado
}

int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q, target;
    scanf("%d %d", &n, &q);

    vector<int> numbers(n);

    // Lendo o vetor
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    // Ordenando o vetor (necessário para busca binária)

    // Resolvendo as consultas
    while (q--) {
        scanf("%d", &target);
        printf("%d\n", findPos(numbers, target));
    }

    return 0;
}
