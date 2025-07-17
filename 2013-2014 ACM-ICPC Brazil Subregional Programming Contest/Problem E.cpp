#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, r;
    cin >> n >> r;

    if (n == r)
    {
        cout << "*";
        return 0;
    }

    vector<bool> retornou(n + 1, false);

    for (int i = 0; i < r; i++)
    {
        int x;
        cin >> x;
        retornou[x] = true;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!retornou[i])
        {
            cout << i << " ";
        }
    }
}