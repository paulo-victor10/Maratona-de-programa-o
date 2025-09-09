#include <bits/stdc++.h>
using namespace std;

/*
   Problema (contexto):
   - "The Last Wish" (Problem G)
   - Recebemos uma string não-vazia com letras minúsculas.
   - O objetivo é modificar o mínimo possível de caracteres para que 
     todas as letras sejam distintas, mantendo apenas letras minúsculas.
   - Se não for possível (string com mais de 26 caracteres), imprimir "IMPOSSIBLE".
   - Caso existam várias soluções possíveis, qualquer uma é válida.

   Solução:
   - Usar um conjunto para rastrear as letras já presentes.
   - Identificar as posições das letras repetidas.
   - Substituir essas letras por letras disponíveis que ainda não aparecem na string.
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    // Se a string tiver mais de 26 letras, impossível deixar todas distintas
    if (s.length() > 26)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    unordered_set<char> usados; // letras já usadas
    vector<int> posicoes;       // posições das letras repetidas

    // Identifica letras repetidas
    for (int i = 0; i < (int)s.length(); ++i)
    {
        if (usados.count(s[i]))
        {
            posicoes.push_back(i); // armazenar posição para trocar
        }
        else
        {
            usados.insert(s[i]); // marca letra como usada
        }
    }

    // Lista de letras disponíveis para substituir
    vector<char> alfabeto;
    for (char c = 'a'; c <= 'z'; ++c)
    {
        if (usados.find(c) == usados.end())
        {
            alfabeto.push_back(c);
        }
    }

    // Substitui letras repetidas pelas disponíveis
    for (int i = 0; i < (int)posicoes.size(); ++i)
    {
        int pos = posicoes[i];
        char nova_letra = alfabeto[i];
        s[pos] = nova_letra;
    }

    // Imprime a string final com todas letras distintas
    cout << s << "\n";
}