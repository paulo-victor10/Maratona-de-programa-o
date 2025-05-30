#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (n == 1)
        cout << "NO";
    else
    {
        auto it=upper_bound(a.begin(),a.end(),a[0]);
        if(it!=a.end()){
            cout<<*it;
        } else cout << "NO";
    }
}