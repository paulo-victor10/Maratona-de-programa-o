#include <bits/stdc++.h>
using namespace std;

int main(){
    int k;
    cin >> k;
    k *= 2;  

    vector<int> v;
    for (int i = 0; i < 4; i++){
        string linha;
        cin >> linha;
        for (char c : linha) {
            if(c != '.'){
                
                v.push_back(c - '0');
            }
        }
    }
    
    bool ok = true;
    
    for (int i = 1; i <= 9; i++){
        int ocorrencias = count(v.begin(), v.end(), i);
        if(ocorrencias > k){
            ok = false;
            break;
        }
    }
    
    cout << (ok ? "YES" : "NO");
    return 0;
}
