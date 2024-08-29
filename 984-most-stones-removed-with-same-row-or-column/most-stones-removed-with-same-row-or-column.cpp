#include <bitset>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    bitset<10000 * 10000> vis;  // Initialize with a max possible size, but will use only up to (n+1)*(n+1) later

    void dfs(set<pair<int, int>>& s, int row, int col, int n) {
        vis[row * (n + 1) + col] = true;

        for (auto temp : s) {
            if (temp.first == row && !vis[row * (n + 1) + temp.second]) {
                dfs(s, row, temp.second, n);
            }
            if (temp.second == col && !vis[temp.first * (n + 1) + col]) {
                dfs(s, temp.first, col, n);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0, maxCol = 0;
        for (auto& temp : stones) {
            maxRow = max(maxRow, temp[0]);
            maxCol = max(maxCol, temp[1]);
        }

        int n = max(maxRow, maxCol);  // Determine the effective grid size (n+1)

        set<pair<int, int>> s;
        for (auto& temp : stones) {
            s.insert({temp[0], temp[1]});
        }

        int k = 0;
        for (auto [i, j] : s) {
            if (!vis[i * (n + 1) + j]) {
                dfs(s, i, j, n);
                k++;
            }
        }

        return stones.size() - k;
    }
};
