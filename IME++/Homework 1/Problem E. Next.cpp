#include <bits/stdc++.h>
#define MOD 1000000000
using namespace std;

int main()
{
    int n, y;
    bool special_add = false;
    cin >> n;
    set<int> s;
    while (n--)
    {
        string op;
        int x;
        cin >> op >> x;
        if (op == "+")
        {
            if (special_add)
            {
                s.insert((x + y)%MOD);
            }
            else
            {
                s.insert(x);
            }
            special_add = false;
        }
        else
        {
            auto it = s.lower_bound(x);
            if (it != s.end())
            {
                cout << *it << endl;
                y = *it;
            }
            else
            {
                cout << -1 << endl;
                y = -1;
            }
            special_add = true;
        }
    }
}