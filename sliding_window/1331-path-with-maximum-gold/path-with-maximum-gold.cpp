class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& visited, vector<vector<int>>& grid, int gold, int& max_gold) {
        visited[row][col] = 1; 
        gold += grid[row][col];
        max_gold = max(gold, max_gold);
        int max_row = grid.size();
        int max_col = grid[0].size();

        // Move directions: up, right, down, left
        int d_row[4] = {-1, 0, 1, 0};
        int d_col[4] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int n_row = row + d_row[i];
            int n_col = col + d_col[i];

            if (n_row >= 0 && n_col >= 0 && n_row < max_row && n_col < max_col && visited[n_row][n_col] == 0 && grid[n_row][n_col] != 0) {
                dfs(n_row, n_col, visited, grid, gold, max_gold);
            }
        }

        // Backtrack: unmark the cell as visited for other paths
        visited[row][col] = 0;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int max_gold = 0;
        int max_row = grid.size();
        int max_col = grid[0].size();

        for (int i = 0; i < max_row; i++) {
            for (int j = 0; j < max_col; j++) {
                if (grid[i][j] != 0) {
                    vector<vector<int>> visited(max_row, vector<int>(max_col, 0));
                    dfs(i, j, visited, grid, 0, max_gold);
                }
            }
        }

        return max_gold;
    }
};
