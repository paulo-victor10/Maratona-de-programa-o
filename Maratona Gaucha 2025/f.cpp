#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, q;
    cin >> n >> q;

    unordered_map<int, int> categ_freq;
    unordered_map<int, int> algor_freq;
    unordered_map<int, int> tema_freq;

    vector<vector<int>> questoes(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int id, c, a, t;
        cin >> id >> c >> a >> t;
        questoes[id] = {c, a, t};
    }

    int limite_categ = (q + 4) / 5;

    vector<int> ans;

    /*
    0-> categoria
    1-> algoritmo
    2-> tematica
    */

    for (int i = 1; i <= n && (int)ans.size() < q; i++)
    {

        int categoria = questoes[i][0], algoritmo = questoes[i][1], tematica = questoes[i][2];

        if (categ_freq[categoria] < limite_categ &&
            algor_freq[algoritmo] < 2 &&
            tema_freq[tematica] == 0)
        {

            categ_freq[categoria]++;
            algor_freq[algoritmo]++;
            tema_freq[tematica]++;
            ans.push_back(i);
        }
    }

    for (int x : ans)
        cout << x << "\n";
}
