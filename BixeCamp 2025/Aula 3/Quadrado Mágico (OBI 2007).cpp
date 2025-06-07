#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, somai = 0, somaj = 0, somad1 = 0, somad2 = 0, somamagica = 0;
    cin >> n;
    int matriz[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> matriz[i][j];
        }

    for (int j = 0; j < n; j++)
    {
        somamagica += matriz[0][j];
    }

    for (int i = 0; i < n; i++)
    {
        somai = 0;
        for (int j = 0; j < n; j++)
        {
            somai += matriz[i][j];
        }
        if (somai != somamagica)
        {
            cout << -1;
            return 0;
        }
    }

    for (int j = 0; j < n; j++)
    {
        somaj = 0;
        for (int i = 0; i < n; i++)
        {
            somaj += matriz[i][j];
        }
        if (somaj != somamagica)
        {
            cout << -1;
            return 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        somad1 += matriz[i][i];
    }
    if (somad1 != somamagica)
    {
        cout << -1;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        somad2 += matriz[i][n - i - 1];
    }
    if (somad2 != somamagica)
    {
        cout << -1;
        return 0;
    }

    cout << somamagica;
}