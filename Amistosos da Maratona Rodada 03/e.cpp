#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int count = 0;

    for (int a = 0; a <= 1000; ++a) {
        int b1 = n - a * a;  
        if (b1 < 0) continue;

        int b2 = m - a;      
        if (b2 < 0) continue;

        if (b1 * b1 == b2) {
            count++;
        }
    }

    cout << count << "\n";
}
