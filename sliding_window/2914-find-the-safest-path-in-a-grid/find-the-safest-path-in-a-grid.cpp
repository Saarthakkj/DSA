
class Solution {
public:
    int d_row[4] = {-1, 0, 1, 0};
    int d_col[4] = {0, 1, 0, -1};

    vector<vector<int>> bfs_distance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;

        // Initialize queue with all thief positions
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) {
                    q.push({r, c});
                    distance[r][c] = 0;
                }
            }
        }

        // BFS to calculate minimum distance to any thief
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int n_row = row + d_row[i];
                int n_col = col + d_col[i];

                if (n_row >= 0 && n_row < n && n_col >= 0 && n_col < n) {
                    if (distance[n_row][n_col] > distance[row][col] + 1) {
                        distance[n_row][n_col] = distance[row][col] + 1;
                        q.push({n_row, n_col});
                    }
                }
            }
        }

        return distance;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> distance = bfs_distance(grid);
        vector<vector<int>> safeness_factor(n, vector<int>(n, -1));
        priority_queue<pair<int, pair<int, int>>> pq;

        // Start BFS from the top-left corner (0, 0)
        pq.push({distance[0][0], {0, 0}});
        safeness_factor[0][0] = distance[0][0];

        while (!pq.empty()) {
            int sf = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            for (int i = 0; i < 4; i++) {
                int n_row = row + d_row[i];
                int n_col = col + d_col[i];

                if (n_row >= 0 && n_row < n && n_col >= 0 && n_col < n) {
                    int new_sf = min(sf, distance[n_row][n_col]);
                    if (new_sf > safeness_factor[n_row][n_col]) {
                        safeness_factor[n_row][n_col] = new_sf;
                        pq.push({new_sf, {n_row, n_col}});
                    }
                }
            }
        }

        return safeness_factor[n-1][n-1];
    }
};