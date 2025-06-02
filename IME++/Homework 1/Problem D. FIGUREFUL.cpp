#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    map<pair<int, int>, string> m;

    while (n--)
    {
        int a, b;
        string s;
        cin >> a >> b >> s;
        m[make_pair(a, b)] = s;
    }

    int t;
    cin >> t;

    while (t--)
    {
        int a, b;
        cin >> a >> b;
        cout << m[make_pair(a, b)] << endl;
    }
}