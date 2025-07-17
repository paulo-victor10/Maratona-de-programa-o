#include <bits/stdc++.h>
using namespace std;

int main()
{
    /*
        Problema: Encontrar o número de triângulos equiláteros possíveis
        em um círculo com N pontos, onde os arcos entre os pontos são dados.

        Exemplo de entrada:
        8
        4 2 4 2 2 6 2 2

        Cada triângulo é formado se conseguirmos dividir o perímetro total
        em 3 partes consecutivas iguais (P/3).
    */

    int n;
    cin >> n; // Número de pontos no círculo
    vector<int> v(n); // Vetor com os tamanhos dos arcos
    int sum = 0; // Perímetro total do círculo

    vector<set<int>> lado(n); // Armazena conexões entre os pontos

    // Leitura dos arcos e cálculo do perímetro total
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }

    // Se o perímetro não é divisível por 3, não é possível formar triângulos equiláteros
    if (sum % 3)
    {
        cout << "0";
        return 0;
    }

    // Duplicamos o vetor para tratar a circularidade
    // Ex.: [4 2 4 2 2 6 2 2 | 4 2 4 2 2 6 2 2]
    v.resize(2 * n);
    for (int i = 0; i < n; i++)
    {
        v[n + i] = v[i];
    }

    int curSum = 0; // Soma acumulada na janela [l, r]
    // Sliding window para encontrar intervalos com soma == P/3
    for (int l = 0, r = 0; r < 2 * n; r++)
    {
        curSum += v[r]; // Expande a janela para a direita

        // Encolhe a janela da esquerda enquanto a soma for maior que P/3
        while (l <= r && curSum > sum / 3)
        {
            curSum -= v[l];
            l++;
        }

        // Quando encontramos um intervalo com soma == P/3
        if (curSum == sum / 3)
        {
            // MODIFICAÇÃO IMPORTANTE:
            // Em vez de salvar o ponto final r, salvamos (r+1)%n
            // para indicar onde o próximo lado do triângulo começa.
            // Isso garante que os lados serão ligados corretamente.
            lado[l % n].insert((r + 1) % n);
            lado[(r + 1) % n].insert(l % n); // Também salva a conexão inversa
        }
    }

    int ans = 0;

    // Para cada ponto do círculo, verificamos:
    // Se ele tem exatamente 2 conexões, isso significa que ele é um vértice de um triângulo
    for (int i = 0; i < n; i++)
    {

        if (lado[i].size() == 2)
        {
            ans++;
        }
    }

    // Dividimos por 3 porque cada triângulo foi contado uma vez para cada vértice
    cout << ans / 3 << "\n";
}
