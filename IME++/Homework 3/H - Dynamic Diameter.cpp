#include <bits/stdc++.h>
using namespace std;

// Limite máximo de nós no grafo (3*10^5 + sobra)
const int MAX = 3 * 1e5 + 10;

vector<vector<int>> adj(MAX); // Lista de adjacência para representar a árvore
int dist[MAX];                // Distâncias usadas na 1ª DFS
int dist2[MAX];               // Distâncias usadas na 2ª DFS

// DFS para calcular distâncias a partir de um nó
void dfs(int v)
{
    for (auto w : adj[v]) // Para cada vizinho w de v
    {
        if (dist[w] == -1) // Se w ainda não foi visitado
        {
            dist[w] = dist[v] + 1; // Atualiza a distância de w
            dfs(w);               // Continua a DFS
        }
    }
}

// Outra DFS para calcular distâncias a partir da segunda ponta
void dfs2(int v)
{
    for (auto w : adj[v])
    {
        if (dist2[w] == -1)
        {
            dist2[w] = dist2[v] + 1;
            dfs2(w);
        }
    }
}

int main()
{
    int n, u, v;
    cin >> n;

    // Caso especial: árvore com apenas 1 nó
    if (n == 1)
    {
        cout << 1 << "\n"; // Se ligarmos o nó n+1, o diâmetro será 1
        return 0;
    }

    // Lê as arestas e monta o grafo
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        u--, v--;                  // Deixa os índices em base 0
        adj[u].push_back(v);       // Adiciona v na lista de u
        adj[v].push_back(u);       // Adiciona u na lista de v
    }

    // 1ª DFS: encontra o nó mais distante do nó 0
    memset(dist, -1, sizeof dist); // Marca todos os nós como não visitados
    dist[0] = 0;
    dfs(0);

    int pos = -1, max_dist = -1;
    // Encontra o nó mais distante de 0
    for (int i = 0; i < n; i++)
    {
        if (dist[i] > max_dist)
        {
            max_dist = dist[i]; // Atualiza a maior distância encontrada
            pos = i;            // Salva a posição do nó mais distante
        }
    }

    // 2ª DFS: encontra a outra ponta do diâmetro
    memset(dist, -1, sizeof dist);
    dist[pos] = 0;
    dfs(pos); // Agora dfs começa do nó mais distante encontrado na 1ª DFS

    int pos2 = -1;
    int diam_original = 0;

    // Encontra o nó mais distante de pos (a outra ponta do diâmetro)
    for (int i = 0; i < n; i++)
    {
        if (dist[i] > diam_original)
        {
            diam_original = dist[i]; // O diâmetro original da árvore
            pos2 = i;                // Outra ponta do diâmetro
        }
    }

    // 3ª DFS: calcula as distâncias a partir da segunda ponta
    memset(dist2, -1, sizeof dist2);
    dist2[pos2] = 0;
    dfs2(pos2);

    // Responde para cada nó
    for (int i = 0; i < n; i++)
    {
        // Se o nó i é uma ponta do diâmetro original:
        // conectar o novo nó nele aumenta o diâmetro em +1
        if (dist[i] == diam_original || dist2[i] == diam_original)
            cout << diam_original + 1 << "\n";
        else
            cout << diam_original << "\n"; // Caso contrário, o diâmetro permanece igual
    }
}
