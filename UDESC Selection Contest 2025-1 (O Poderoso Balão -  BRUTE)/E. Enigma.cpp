#include <bits/stdc++.h>
using ll = long long;
#define MOD 1000000007
using namespace std;
/*
X+Y=(A+B) + (A-B)
X+Y=2A
A=(X+Y)/2

X-Y=(A+B) - (A-B)
X-Y=A + B - A + B
B= (X - Y)/2
*/
int main()
{
    ll x, y;
    cin >> x >> y;

    ll a, b;
    // A=(X+Y)/2
    a = (x + y) / 2;
    // B= (X - Y)/2
    b = (x - y) / 2;

    cout<<b<<" "<<a;
}