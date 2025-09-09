/*
problema G)

usar um map e guardar {acertos, penalty}

map<int,pair<int,int>> mapa(n,{0,0}); //tam n e inicializado com pairs {0,0} pra cada chave correspondente a uma equipe

n=3 m=4;
mapa=({1,{0,0}},{2,{0,0}},{3,{0,0}})

mapa[1]->como saber em qual posição do mapa está essa chave?

2 7; mapa[2].first++; mapa[2].second+=7; mapa=({2,{1,7}}, {1,{0,0}}, {3,{0,0}})
3 5; mapa[3].first++; mapa[3].second+=5; mapa=({3, {1,5} }, {2, {1,7} }, {1,{0,0}})
1 6; mapa[1].first++; mapa[1].second+=6; mapa=({3, {1,5} }, {1, {1,6}}, {2, {1,7} })
1 9; mapa[1].first++; mapa[1].second+=9; mapa=({1, {2,15}}, {3, {1,5} }, {2, {1,7} })

tem que fazer um ordered_set de pair<pair<int,int>, int> -> {{Q,P}, ID} (tem no repo do IME)

1) remove do set
2) modificar no map
3) insere no set
4) printa a posição do elemento usando ordered_set

//order_of_key returns the position of a given element
cout << s.order_of_key(m[1]) << "\n"; // 2
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<pair<int,int>,int>, null_type, less<pair<pair<int,int>,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

ordered_set s;

int main()
{
    int n, m;
    cin >> n >> m;
    map<int, pair<int, int>> mapa;

    for (int i = 1; i <= n; i++)
    {
        mapa[i].first = 0; //q(question)
        mapa[i].second = 0; //p(penalty)
        auto qpt=make_pair(mapa[i],i); //pair<pair<int,int>, int> -> {{Q,P}, ID}
        s.insert(qpt);
    }

    while (m--)
    {
        int t, p; cin>>t>>p;
        auto qpt=make_pair(mapa[t],t); //pair<pair<int,int>, int> -> {{Q,P}, ID}
        s.erase(qpt);

        mapa[t].first--; mapa[t].second+=p;

        qpt=make_pair(mapa[t],t);
        s.insert(qpt); 
        qpt=make_pair(mapa[1],1);
        
        cout<<s.order_of_key(qpt) + 1<<"\n";
    }
}