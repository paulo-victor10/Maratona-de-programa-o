#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 10;
vector<vector<int>> adj(MAX); //lista de adj
vector<int> mark(MAX); //vetor para marcar quais vertices tem um gato
int custo[MAX]; //vetor para armazenar em cada posição o custo para se chegar la sendo que custo representa quantos gatos em sequencia voce tem que passar ao caminhar

int ans = 0; //contar quantas folhas(restaurantes) é possivel ir sem passar por mais do que m gatos seguidos
int n, m;
void dfs(int u, int pai, int sequence, int max_atual) //dfs modificada para o problema com muitos parametros
/*
int u=nó atual chamando a dfs
int pai representa o nó que vem antes de u o que é util para sabermos de u é folha ou não
int sequence assume valores 0 ou 1 e nos diz se o nó u está numa sequencia de vertices que tem gatos, e também serve para nos dizer se uma sequencia foi quebrada
int max_atual representa o custo local para o nó u; quando uma sequencia é quebrada por um nó não marcado, esse nó não marcado tem custo local 0 porque localmente ele nao tem gatos
*/
{
    bool eFolha = true; 

    for (int v : adj[u]) //para cada v na lista de adj de u

    {
        if (v != pai) //se na lista tiver algum v que não foi o pai de u, então u não é folha. Mas se u só tiver o pai dele na lista então u é folha
            eFolha = false;

        if (custo[v] == -1) //isso nos diz que v não foi processado ainda 
        {
            if (!mark[v]) //se v não é marcado, seu custo local é 0 e por ventura ele quebrou uma sequencia de nós marcados
            {
                custo[v] = 0;
            }
            else if (!mark[u]) //se v é marcado, mas seu pai u não é então v é o primeiro nó marcado de uma POSSÍVEL sequencia de nós marcados. 
            //Portanto, ele deve começar com custo local igual a 1 porque ele não acumulou o custo de uma sequencia
            {
                custo[v] = 1;
            }

            if (mark[v] && mark[u] && sequence) //se v e u são marcados e ainda são sequencia então o custo local de v deve acumular o custo que vem de u
            //e ainda somar a seu custo (custo de v) que é 1
            {
                custo[v] = custo[u] + 1;
            }
            int prox_max = max(max_atual, custo[v]); 
            /*
            aqui devemos passar adiante a informação que representa o custo do caminho da raiz até o nó v
            se numa sequencia de nós marcados ele conseguiu superar o maior custo até agora então devemos atribuir ele ao max_atual
            */
            dfs(v, u, mark[v], prox_max); //passamos proximo nó, pai, se ele é marcado, e o custo local
        }
    }
    if (eFolha && max_atual <= m)
        ans++;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> mark[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(custo, -1, sizeof custo);

    custo[0] = mark[0];
    dfs(0, -1, mark[0], custo[0]);

    cout << ans << endl;

    
}