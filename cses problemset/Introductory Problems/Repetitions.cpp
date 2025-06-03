#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int m, n;
    int di[4] = {-1, 0, 1, 0};
    int dj[4] = { 0, 1, 0, -1};

    // Função DFS para marcar as células conectadas como visitadas
    void dfs(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '0';  // Marca a célula atual como visitada
        for (int k = 0; k < 4; ++k) {
            int ii = i + di[k];
            int jj = j + dj[k];
            if (ii < 0 || ii >= m || jj < 0 || jj >= n)
                continue;
            if (grid[ii][jj] == '1')
                dfs(grid, ii, jj);
        }
    }

    // Função que conta o número de ilhas na grade
    int numIslands(vector<vector<char>>& grid) {
        // Verifica se a grade está vazia
        if (grid.empty() || grid[0].empty())
            return 0;

        m = grid.size();
        n = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    ++cnt;
                    dfs(grid, i, j);
                }
            }
        }
        return cnt;
    }
};
