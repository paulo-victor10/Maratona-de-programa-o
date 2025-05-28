#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();

    int pos = -1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            pos = i;
            break;
        }
    }
    if (pos == -1)
    {
        pos = 0;
    }

    string t;
    t.reserve(n - 1);
    for (int i = 0; i < n; i++)
    {
        if (i == pos)
            continue;
        {
            t.push_back(s[i]);
        }
    }
    int start = 0;
    while (start + 1 < (int)t.size() && t[start] == '0')
    {
        start++;
    }
    cout << t.substr(start) << "\n";
}