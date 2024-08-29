#include <bitset>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    void dfs(set<pair<int, int>>& s, int row, int col, bitset<10000 * 10000>& vis, int M) {
        vis[row * M + col] = true;

        for (auto temp : s) {
            if (temp.first == row && !vis[row * M + temp.second]) {
                dfs(s, row, temp.second, vis, M);
            }
            if (temp.second == col && !vis[temp.first * M + col]) {
                dfs(s, temp.first, col, vis, M);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0, maxCol = 0;
        for (auto& temp : stones) {
            maxRow = max(maxRow, temp[0]);
            maxCol = max(maxCol, temp[1]);
        }

        int n = max(maxRow, maxCol) + 1;  // Determine the effective grid size
        bitset<10000 * 10000> vis;  // You can reduce the size based on `n` if it fits within 10,000 * 10,000
        set<pair<int, int>> s;

        for (auto& temp : stones) {
            s.insert({temp[0], temp[1]});
        }

        int k = 0;
        for (auto [i, j] : s) {
            if (!vis[i * n + j]) {
                dfs(s, i, j, vis, n);
                k++;
            }
        }

        return stones.size() - k;
    }
};
