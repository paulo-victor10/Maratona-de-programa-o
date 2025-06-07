#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x, y;
    cin >> n;
    x = n / 2;
    y = x;
    if (n % 2 == 0)
    {
        if (x % 2 == 0) cout << "YES";
        else
        {
            x--;y++;
            if (x + y == n && x > 0) cout << "YES";
            else cout << "NO";
        }
    }
    else cout << "NO";
}