#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool div2(string s)
{
    int x = s.back() - '0';
    return (x % 2 == 0);
}

bool div3(string s)
{
    ll sum = 0;
    for (char c : s)
    {
        sum += c - '0';
    }
    return (sum % 3 == 0);
}

bool div4(string s)
{
    int tam = s.size();
    int x = (s[tam - 1] - '0');
    if (tam > 1)
    {
        x += 10 * (s[tam - 2] - '0');
    }
    return (x % 4 == 0);
}

bool div5(string s)
{
    int x = s.back();
    return (x == '5' || x == '0');
}

bool div6(string s)
{
    return div2(s) && div3(s);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string n;
        cin >> n;
        bool achou = false;

        if (div2(n))
        {
            cout << 2;
            achou = true;
        }
        if (div3(n))
        {   
            if(achou) cout<<" ";
            cout << 3;
            achou = true;
        }
        if (div4(n))
        {
            if(achou) cout<<" ";
            cout << 4;
            achou = true;
        }
        if (div5(n))
        {
            if(achou) cout<<" ";
            cout << 5;
            achou = true;
        }
        if (div6(n))
        {
            if(achou) cout<<" ";
            cout << 6;
            achou = true;
        }
        if (!achou)
            cout << -1;
        cout << "\n";
    }
}
