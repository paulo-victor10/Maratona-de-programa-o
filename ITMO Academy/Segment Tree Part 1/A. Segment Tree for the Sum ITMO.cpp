#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct segtree //criando a estrutura da segtree
{
    int size; //tamanho da segtree
    vector<ll> sums;  

    void init(int n) //inicializando a segtree com n=size do array original
    {
        size = 1;
        while (size < n) //enquanto o size nao for maior que n iremos aumentar o tamanho do vetor sums para ser o mais proximo de uma potencia de 2
            size *= 2; 
        sums.assign(2 * size, 0); //inicializando o vetor vazio
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    segtree st;
    st.init(n);
}