#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 300;

ll matrix[N][N], adj[N][N];

int main()
{
    int n;
    cin >> n; // lê o tamanho da matriz (n vértices do grafo)

    // leitura da matriz de distâncias
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    // verificação de consistência usando a desigualdade do Floyd-Warshall
    // se existir um caminho indireto mais curto que o informado, a matriz é inválida
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] > matrix[i][k] + matrix[k][j])
                {
                    cout << "-1\n"; // matriz não representa distâncias mínimas válidas
                    return 0;
                }
            }
        }
    }

    // se passou na checagem, imprime a matriz original
    // a matriz de distancias minimas pelo problema ja e uma matriz de adj valida
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}