#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int count = 0;

    for (char c : s)
    {
        if (c == '(')
            count++;
        else
            count--;

        if (count < 0)
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    cout << s;
    for (int i = 0; i < count; i++)
    {
        cout << ')';
    }
    cout << "\n";
}