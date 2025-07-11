#include <bits/stdc++.h>

using namespace std;

// grafo bipartido
// se encontrar a qtd de componentes conexos no grafo e fizer -1 encontra a resposta
// um componente conexo quer dizer que para todas as coordenadas que pertencem a esse componente, eu posso
// deslizar de qualquer ponto para o o outro dentro desse componente
// então basta criar k novos pontos cuja coordenadas liguem os n componentes conexos

const int MAX = 1010; //DICA: NUNCA esqueça de colocar um chorinho no MAX

set<int> adj[MAX * 2]; //de 0 a 999 é reservado para as listas do eixo x 
//e de 1000 a 1999 é reservado para as listas do eixo y
vector<bool> vis(MAX * 2);

void dfs(int u) //essa dfs pecorre todo um componente conexo a partir de qualquer vertice de qualquer eixo (x ou y)
{
    vis[u] = true;
    for (int v : adj[u])
    {
        if (!vis[v])
            dfs(v);
    }
}

int main()
{
    int n;
    cin>>n;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        adj[x].insert(y + MAX); //já que x e y podem ser o mesmo numero, mas em eixos diferentes 
        //para nao bagunçar as listas de adj é possivel reservar os primeiro 1000 espaços para o eixo x e o resto para o eixo y
        //e usando um set invés de vector é possivel manter a ordem e integridade das listas de forma mais eficiente
        adj[y + MAX].insert(x);
    }

    int ans = 0; //vai contar quantos componentes conexos existem

    for (int i = 0; i < MAX * 2; i++)
    {
        if (!vis[i] and !adj[i].empty()) //toda vez que um vertice não tiver sido visitado 
        //e tambem tenha um vertice do outro eixo em sua lista de adj, iremos chamar a dfs
        {
            dfs(i);
            ans++; //quando a dfs termina, ou seja, foi pecorrido e marcado todo um componente conexo, podemos contar
        }
    }
    cout<<ans-1;
}