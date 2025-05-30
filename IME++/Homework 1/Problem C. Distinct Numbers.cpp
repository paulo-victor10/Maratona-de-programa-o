#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    set <int> x;

    for (int i = 0; i < n; i++)
    {   
       int y;
       cin>>y;
       x.insert(y);
    }
    cout<<x.size();
}