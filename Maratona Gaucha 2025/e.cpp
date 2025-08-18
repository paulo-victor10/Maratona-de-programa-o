#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;

    vector<vector<ll>> votos(n, vector<ll>(n));

    for (ll j = 0; j < n; j++)
    {
        for (ll i = 0; i < n; i++)
        {
            cin >> votos[i][j];
        }
    }

    vector<ll> menor_pivos(n,-1);
    vector<ll> maior_pontos(n, -1);

    for (ll candidato = 0; candidato < n; candidato++)
    {
        vector<ll> prefix(n);
        prefix[0] = votos[0][candidato];
        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + votos[i][candidato];
        }
        for (ll pivo = 1; pivo <= n; pivo++)
        {
            ll soma_antes;
            if (pivo >= 2)
                soma_antes = prefix[pivo - 2];
            else
                soma_antes = 0;

            ll soma_depois;
            if (pivo >= 1)
                soma_depois = prefix[n - 1] - prefix[pivo - 1];
            else
                soma_depois = prefix[n - 1]; 

            ll soma = (n - pivo) * soma_antes - soma_depois;

            if (soma > maior_pontos[candidato])
            {
                maior_pontos[candidato] = soma;
                menor_pivos[candidato] = pivo;
            }
            else if (soma == maior_pontos[candidato])
                menor_pivos[candidato] = min(menor_pivos[candidato], pivo);
        }
    }

    for (int p : menor_pivos)
        cout << p << " ";
    cout << "\n";

    int ans = 0;

    for (int i = 1; i < n; i++)
    {
        if (maior_pontos[i] > maior_pontos[ans])
        {
            ans = i;
        }
        else if (maior_pontos[i] == maior_pontos[ans])
        {
            if (menor_pivos[i] < menor_pivos[ans])
                ans = i;
        }
    }

    cout << ans + 1 << " " << maior_pontos[ans] << "\n";
}
