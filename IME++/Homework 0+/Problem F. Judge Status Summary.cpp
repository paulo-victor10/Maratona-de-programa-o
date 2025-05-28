#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main()
{
    int n;
    cin >> n;
    unordered_map<string, int> m = {
        // AC , WA , TLE , and RE ,
        {"AC", 0},
        {"WA", 0},
        {"TLE", 0},
        {"RE", 0},
    };

    while (n--)
    {
        string s;
        cin >> s;
        m[s]++;
    }

    // cout << "AC x " << m["AC"] << endl;
    // cout << "WA x " << m["WA"] << endl;
    // cout << "TLE x " << m["TLE"] << endl;
    // cout << "RE x " << m["RE"] << endl;
    vector<string> v ={"AC", "WA", "TLE", "RE"};

    for(auto& chave:v){
        cout<<chave<<" x "<<m[chave]<<endl;
    }
}