#include <bits/stdc++.h>
using namespace std;

int main() {
    int p, q;
    cin >> p >> q;

    double prob = (p * 1.0 * p + q * 1.0 * q) / (100.0 * (p + q));

    cout << fixed << setprecision(15) << prob << endl;
}