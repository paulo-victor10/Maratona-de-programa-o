#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*
   Problema (contexto):
   - Temos um array de inteiros c[0..n-1].
   - Podemos andar no array de duas formas:
       1) De posição i para i+1 (se existir).
       2) De posição i para a última ocorrência futura de c[i].
   - A tarefa é descobrir o menor número de passos para ir de c[0] até c[n-1].

   Solução:
   - Modelamos como um grafo: cada índice do array é um nó.
   - Adicionamos arestas:
       - i → i+1 (movimento natural no array).
       - i → próxima posição j onde c[i] aparece (movimento por "teleporte").
   - Executamos BFS (Breadth-First Search) a partir do nó 0,
     pois o grafo é não ponderado (todas arestas têm peso 1).
   - A resposta será dist[n-1], ou seja, a menor distância do índice 0 ao índice n-1.
*/

const int N = 2e5 + 10; // limite máximo de nós
int dist[N], par[N];
vector<int> adj[N];
queue<int> q;

// BFS padrão para calcular menor distância em grafo não ponderado
void bfs(int s)
{
    memset(dist, 63, sizeof(dist)); // inicializa distâncias com "infinito"
    dist[s] = 0;
    q.push(s);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : adj[u])
        {
            if (dist[v] > dist[u] + 1)
            {
                par[v] = u;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    // ligações i -> i+1
    for (int i = 0; i < n; i++)
    {
        if (i + 1 < n)
            adj[i].push_back(i + 1);
    }

    // ligações i -> última ocorrência futura de c[i]
    unordered_map<int, int> m;
    for (int i = n - 1; i >= 0; i--)
    {
        if (m.count(c[i]))
            adj[i].push_back(m[c[i]]);
        m[c[i]] = i;
    }

    // BFS a partir do índice 0
    bfs(0);

    // resposta: menor distância até o último índice
    cout << dist[n - 1];
}

/*
Exemplo:
Entrada:
5
1 2 3 2 1

Explicação do grafo:
- i -> i+1: (0->1, 1->2, 2->3, 3->4)
- teleportes: (0->4), (1->3)

Caminho mínimo 0 -> 4 (teleporte direto).
Saída: 1
*/