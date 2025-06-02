#include <bits/stdc++.h>
using namespace std;

/*
    Verifica se as duas strings (a e b) estão contidas como substrings dentro da string 'merged'.
    Isso garante que nossa superstring final realmente contém ambas as palavras.
*/
bool contem_substr(string merged, string a, string b) {
    return merged.find(a) != string::npos && merged.find(b) != string::npos;
}

/*
    Une duas strings a e b, aproveitando k caracteres que estão sobrepostos (iguais).
    Exemplo: a = "abcde", b = "cdefg", k = 3 => retorna "abcdefg" (sem repetir o "cde")
*/
string merge_sobreposicao(string a, string b, int k) {
    return a + b.substr(k); // b.substr(k) ignora os k caracteres iniciais de b que já estão no final de a
}

/*
    Gera a menor superstring que contém s1 e s2 como substrings,
    explorando todas as sobreposições possíveis entre elas.
*/
int solution(string s1, string s2) {
    // Se uma das strings já está contida totalmente na outra, a maior já é suficiente
    if (s1.find(s2) != string::npos || s2.find(s1) != string::npos)
        return max(s1.size(), s2.size());

    // Caso contrário, iniciamos assumindo que não há sobreposição
    int tam_min = s1.size() + s2.size();

    // Tenta sobrepor o final de s1 com o início de s2
    for (int k = 0; k <= min(s1.size(), s2.size()); k++) {
        // Verifica se os últimos k caracteres de s1 são iguais aos primeiros k de s2
        if (s1.substr(s1.size() - k) == s2.substr(0, k)) {
            string merged = merge_sobreposicao(s1, s2, k);
            if (contem_substr(merged, s1, s2)) {
                tam_min = min(tam_min, (int)merged.size());
            }
        }
    }

    // Agora tenta o contrário: sobrepor final de s2 com início de s1
    for (int k = 0; k <= min(s1.size(), s2.size()); k++) {
        if (s2.substr(s2.size() - k) == s1.substr(0, k)) {
            string merged = merge_sobreposicao(s2, s1, k);
            if (contem_substr(merged, s2, s1)) {
                tam_min = min(tam_min, (int)merged.size());
            }
        }
    }

    return tam_min; // Retorna o menor tamanho encontrado de superstring válida
}

/*
    Função principal. Lê a entrada e resolve conforme o número de strings.
    - Se for apenas 1 string, imprime seu próprio tamanho.
    - Se forem 2 strings, chama a função de solução para calcular a menor superstring.
*/
int main() {
    int n;
    cin >> n;

    if (n == 1) {
        string s;
        cin >> s;
        cout << s.size() << endl;
    } else {
        string s1, s2;
        cin >> s1 >> s2;
        cout << solution(s1, s2) << endl;
    }
}
