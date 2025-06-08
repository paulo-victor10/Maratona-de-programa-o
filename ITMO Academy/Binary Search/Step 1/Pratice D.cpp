#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    cin>>k;
    while (k--)
    {
        int l, r;
        cin >> l >> r;

       auto itleft=lower_bound(a.begin(),a.end(),l);
       auto itright=upper_bound(a.begin(),a.end(),r);

       cout<<itright - itleft<<" ";
        
    }
}