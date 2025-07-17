#include <bits/stdc++.h>

using namespace std;

/*
1) Ler a matriz com L linhas e C colunas, que indica a posição atual dos containers (cada número único de 1 a L*C)

2) Para cada linha atual i:
    - Pegar o primeiro número da linha para descobrir qual linha original ela representa
    - Verificar se todos os números daquela linha pertencem a essa mesma linha original
    - Se algum número não pertencer, não dá pra arrumar só com troca de linhas e colunas, imprimir "*" e sair
    - Se todos estiverem corretos, guardar essa associação em linha_atual[i]

3) Para cada coluna atual j:
    - Pegar o primeiro número da coluna para descobrir qual coluna original ela representa
    - Verificar se todos os números daquela coluna pertencem a essa mesma coluna original
    - Se algum número não pertencer, imprimir "*" e sair
    - Se todos estiverem corretos, guardar essa associação em coluna_atual[j]

4) Agora temos os vetores linha_atual e coluna_atual, que são permutações das linhas e colunas originais

5) Para saber o mínimo de movimentos:
    - Contar os ciclos na permutação das linhas; cada ciclo de tamanho k exige k-1 trocas para arrumar
    - Contar os ciclos na permutação das colunas do mesmo jeito
    - Somar as trocas de linhas com as de colunas, que é o total mínimo de trocas necessárias

6) Imprimir o resultado final

Exemplo:

5 4
13 15 14 16 -> (13-1)/4; essa linha seria a linha 3 (1...4); a coluna (13-1)%4=0; seria a primeria coluna; 
5 7 6 8
9 11 10 12
1 3 2 4
17 19 18 20

Por fim, verificar se dá pra arrumar só com troca de linhas e colunas, e se sim, calcular o número mínimo de trocas.
*/



int contarTrocas(vector<int> &p)
{
    int n = (int)p.size();
    vector<bool> vis(n, false);
    int trocas = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            int ciclos = 0;
            int atual = i;
            while (!vis[atual])
            {
                vis[atual] = true;
                atual = p[atual];
                ciclos++;
            }
            trocas += ciclos - 1;
        }
    }
    return trocas;
}

int main()
{
    int l, c;
    cin >> l >> c;
    vector<vector<int>> matriz(l, vector<int>(c));

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> matriz[i][j];
        }
    }

    vector<int> linha_atual(l, -1);
    vector<int> coluna_atual(c, -1);

    for (int i = 0; i < l; i++)
    {
        int x = matriz[i][0];
        int linha_esperada = (x - 1) / c;

        for (int j = 0; j < c; j++)
        {
            int k = matriz[i][j];
            int r = (k - 1) / c;
            if (r != linha_esperada)
            {
                cout << "*";
                return 0;
            }
        }
        linha_atual[i] = linha_esperada;
    }

    for (int j = 0; j < c; j++)
    {
        int x = matriz[0][j];
        int coluna_esperada = (x - 1) % c;
        for (int i = 0; i < l; i++)
        {
            int k = matriz[i][j];
            int y = (k - 1) % c;
            if (y != coluna_esperada)
            {
                cout << "*";
                return 0;
            }
        }
        coluna_atual[j] = coluna_esperada;
    }

    int ans=contarTrocas(linha_atual) + contarTrocas(coluna_atual);
    cout<<ans;
}