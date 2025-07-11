#include <bits/stdc++.h>
using namespace std;

int n, m, ans;

//não precisei de vetor de visitados
const int MAX = 1e4 + 10; //10010
vector<vector<int>> adj(MAX); //lista de adjacencia; quando for par tem 2 filhos e quando é impar tem 1
vector<int> dist(MAX, -1); //vetor que armazena distacnai
//o tamanho desse dist é o tamanho MAX e cada elemento nele é inicializado como -1

void bfs(int s)
{
    queue<int> q; //fila da bfs(vizinhos)
    q.push(s); //push na raiz
    dist[s] = 0; //a dist da raiz pra ela mesma é 0
    //dist[6]=0
    bool achou = false; // serve pra parar quando achou o nó de onde comecei
    while ((!q.empty()) || (!achou)) //continua até que esteja vazia ou então até que encontre de onde começou
    {
        int v = q.front(); //o nó no começo da fila que está sendo processado
        q.pop(); //tira o começo da fila pq eu ja to processando ele aqui


        //a lista de adj é feita de forma dinamica antes de cada loop processando os vizinhos
        //para esse problema ela é feita da seguinte forma:
    
        adj[v].push_back(v + 1); //pega os vizinhos do v e coloca na fila. Aí eles esperam a vez deles 
        //esse primeiro viziho será sempre o seu sucessor 
        if (v % 2 == 0) //o segundo vizinho do v pode ser a metade dele se v for par
            adj[v].push_back(v / 2);
        else //se v for impar então ele nao tem segundo vizinho
            adj[v].push_back(v);

        for (auto u : adj[v]) //loop que processa os vizinhos diretos de v
        {
            if (dist[u] == -1) //se a dist é -1 então eu não mexi nele ainda, logo tenho que processa-lo agora
            {
                dist[u] = dist[v] + 1; //agora eu digo que a distancia de u para v é a distancia de v + 1
                //dist[4] = -1
                //dist[3] = 1
                //dist[4] = dist[3] + 1 = 1 + 1 = 2
                q.push(u); 
            }

            if (u == n) //se u for quem eu to buscando
            {
                ans = dist[u]; //a resposta vai ser a dist de u para a raiz s
                achou = true; //marco que eu achei a resposta
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    if (n >= m) //n=10 m=1; deminuir 9 vezes; 10-1 
    {
        cout << n - m;
        return 0;
    }
    bfs(m);
    cout << ans;
}