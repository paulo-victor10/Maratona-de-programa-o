#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, m;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<bool> p(n, false);
        for (int i = 0, j; i < m; i++)
        {
            cin >> j;
            p[j - 1] = true;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                if (p[j] && a[j] > a[j + 1]) // verifica se pode trocar e se vale a pena fazer a troca
                {
                    swap(a[j], a[j + 1]);
                }
            }
        }

        bool ordenado = true;
        for (int i = 1; i < n; i++)
        {
            if (a[i - 1] > a[i])
            {
                ordenado = false;
                break;
            }
        }
        if (ordenado)
        {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }
}
