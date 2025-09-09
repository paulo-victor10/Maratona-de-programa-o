#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const float N = 1e8;

struct Runner
{
    string nome;
    float a, b;
};

int main()
{
    int n;
    cin >> n;
    vector<Runner> v(n);

    for (int i = 0; i < n; i++)
    {
        string s;
        float x, y;
        cin >> s >> x >> y;

        v[i].nome = s;
        v[i].a = x;
        v[i].b = y;
    }

    float melhor_tempo = N;
    vector<string> melhor_time;

    for (int i = 0; i < n; i++)
    {
        vector<pair<float, string>> w;
        for (int j = 0; j < n; j++)
        {
            if (j == i)
                continue;
            w.push_back({v[j].b, v[j].nome});
        }
        sort(w.begin(), w.end());

        if (w.size() < 3)
            continue; // até pegar os 3 melhores

        float total = v[i].a + w[0].first + w[1].first + w[2].first;

        if (total < melhor_tempo)
        {
            melhor_tempo = total;
            melhor_time = {v[i].nome, w[0].second, w[1].second, w[2].second};
        }
    }

    cout << melhor_tempo << "\n";
    for (auto &x : melhor_time)
        cout << x << "\n";
}