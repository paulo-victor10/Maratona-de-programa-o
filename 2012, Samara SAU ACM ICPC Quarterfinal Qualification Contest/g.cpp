#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    if (s.length() > 26)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    unordered_set<char> usados;
    vector<int> posicoes;

    for (int i = 0; i < (int)s.length(); ++i)
    {

        if (usados.count(s[i]))
        {
            posicoes.push_back(i);
        }
        else
        {
            usados.insert(s[i]);
        }
    }

    vector<char> alfabeto;
    for (char c = 'a'; c <= 'z'; ++c)
    {

        if (usados.find(c) == usados.end())
        {
            alfabeto.push_back(c);
        }
    }

    for (int i = 0; i < (int)posicoes.size(); ++i)
    {
        int pos = posicoes[i];
        char nova_letra = alfabeto[i];
        s[pos] = nova_letra;
    }

    cout << s << "\n";
}