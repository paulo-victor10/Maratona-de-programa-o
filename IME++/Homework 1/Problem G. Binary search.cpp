#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,q;
    scanf("%d %d", &n, &q);
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    while(q--){
        int x;
        scanf("%d", &x);
        auto it=lower_bound(a.begin(),a.end(),x);
        if (it!=a.end() && *it==x)
            printf("%d\n", (int)(it - a.begin()));
        else
            printf("-1\n");
    }
}