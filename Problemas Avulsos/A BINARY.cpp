#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        int l = 0;
        int r = n - 1;
        bool achou = false;
        while (r >= l) {
            int m = (l + r) / 2;
            if (a[m] == x) {
                achou = true;
                break;
            } else if (a[m] < x) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        if (achou) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
