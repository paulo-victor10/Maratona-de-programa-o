#include <bits/stdc++.h>
using ll = long long;
#define MOD 1000000007
using namespace std;

/* Escolher duas posições i, j (1 ≤ i, j ≤ N ) e trocar de lugar os caracteres Si e Sj , ou
seja, Si vai para a posição j e vice-versa.*/

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    char menor = *s.begin();
    for (auto &c : s)
    {
        menor = min(c, menor);
    }

    int iswap=-1,jswap=-1;

    for (int i = 0; i < n; i++)
    {
        if (s[i] > menor)
        {
            iswap=i;
            break;
        }
    }

    if (iswap==-1)
    {
        cout<<s;
        return 0;
    }
    

    for (int j = n - 1; j > iswap; j--)
    {
        if (s[j] == menor)
        {
            jswap=j;
            break;
        }
    }

    if (jswap != -1)
    {
        swap(s[iswap],s[jswap]);
    }
    
    cout<<s;
}