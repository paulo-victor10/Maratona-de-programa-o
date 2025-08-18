#include <bits/stdc++.h>

using namespace std;
using ll=long long;

const int N=1e6;

vector<bool> crivo(int x){
    vector<bool> ePrimo(x+1,true);
    ePrimo[0] = ePrimo[1]=false;

    for (int i = 2; i * i<=x; i++)
    {
        if(ePrimo[i]){
            for (int j = i*i; j<=x; j+=i)
            {
                ePrimo[j]=false;
            }
        }
    }
    return ePrimo;
}

int main(){
    int t; cin>>t;
    auto primos = crivo(N);
    vector<int> dp(N+1,0);
    for (int i = 1; i <=N; i++)
    {
        if(primos[i]){
            dp[i]+=dp[i-1] + 1;
        }
        else
        {
            dp[i]+=dp[i-1];
        }
    }

    while (t--)
    {
        int l,r; cin>>l>>r;
        cout<<dp[r]-dp[l-1]<<"\n";
    }
    
}