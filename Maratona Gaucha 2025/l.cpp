#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll MAX = 1e10;
const int N = 1e7 + 10;

// int st[4*N],v[N];

int bit[N];

void add(int p, int v)
{
    for (p += 2; p < N; p += p & -p)
        bit[p] += v;
}

int query(int p)
{
    int r = 0;
    for (p += 2; p; p -= p & -p)
        r += bit[p];
    return r;
}

int rangesum (int a, int b){
    return query(b) -  (a ? query(a-1) : 0);
}

int main()
{
    int q; cin>>q;

    while (q--)
    {
        string op; cin>>op;
        if(op=="I"){
            int a; cin>>a;
            add(a,1);
        }
        if(op=="C"){
            int a,b; cin>>a>>b;
            cout<<rangesum(a,b)<<"\n";
        }
    }
    
}