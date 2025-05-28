#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    unordered_map<int, vector<pair<int, int>>> soma_pares;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int soma = a[i] + a[j];
            soma_pares[soma].push_back(make_pair(i, j));
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        int x; // target
        cin >> x;
        int count = 0;

        for (auto &[soma1, pares1] : soma_pares)
        {
            int soma2 = x - soma1;
            if (!soma_pares.count(soma2))
                continue;

            auto &pares2 = soma_pares[soma2];

            for (auto &[i1, j1] : pares1)
            {
                for (auto &[i2, j2] : pares2)
                {
                    if (i1 != i2 && i1 != j2 && j1 != i2 && j1 != j2)
                    {
                        vector<int> ans = {i1, j1, i2, j2};
                        sort(ans.begin(), ans.end());
                        if (ans[0] < ans[1] && ans[1] < ans[2] && ans[2] < ans[3])
                        {
                            count++;
                        }
                    }
                }
            }
        }
        cout << count/6 << endl;
    }
}