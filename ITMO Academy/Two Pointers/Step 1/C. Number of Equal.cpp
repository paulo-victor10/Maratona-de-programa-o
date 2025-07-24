#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ll n, m;
    cin >> n >> m;

    vector<ll> a(n);
    vector<ll> b(m);

    for (ll i = 0; i < n; i++)
    {
        cin >> a[i]; //vetor a
    }
    for (ll i = 0; i < m; i++)
    {
        cin >> b[i]; //vetor b
    }

    //só pra garantir que isso aqui ta ordenado mesmo
    //acredite se quiser o problema mesmo dizendo non decreasing order ainda tive que ordenar os vetores
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll count = 0, i = 0, j = 0;

    while (i < n && j < m) //percorre os dois vetores ao mesmo tempo sendo i o pointer para a e j o pointer para b
    {
        if (a[i] < b[j]) //se os elementos forem diferentes movemos o i ou j conforme a ordem
            i++;
        else if (a[i] > b[j])
            j++;
        else //eles são iguais!
        {
            ll x = a[i]; //x será o elemento em comum entre a[i] e b[j]
            ll count_a = 0, count_b = 0; //contar quantos elementos iguais a esse elemento em comum aparecem em seus respectivos vetores
            while (i < n && a[i] == x) //andando pelo vetor a enquanto estivermos no seu limite e os valores em a forem iguais ao x
            {
                count_a++; //a medida que encontramos valores iguais vamos incrementar o contador
                i++; //avançamos o pointer i para o proximo elemento de a
            }
            while (j < m && b[j] == x) //mesma coisa em b
            {
                count_b++;
                j++;
            }

            count += count_a * count_b; //no final o contador final será incrementado com base no produto entre quantos elementos iguais 
            //existem em a e em b
        }
    }

    cout << count << "\n";
}