#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll k, n, q, Sn = 0, ct = 0, cx = 0;

    ios::sync_with_stdio(0);
    cin.tie(0);

    scanf("%lld", &k);

    while(k--){
        scanf("%lld%lld", &n, &q);

        Sn = ((n+1)*n)/2;

        if(n >= q) printf("1\n");
        else if(Sn >= q){
            while(n){
                ct+=n;
                cx++;
                if(ct>=q) break;                
                n--;
            }
            printf("%lld\n", cx);
        }
        else printf("IMPOSSIVEL\n");

        n = 0, q = 0, Sn = 0, ct = 0, cx = 0;
    }
}