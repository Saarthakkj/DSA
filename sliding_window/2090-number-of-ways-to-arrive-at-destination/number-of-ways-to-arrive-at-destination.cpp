#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    const long long mod = 1e12 + 7;
    const long long mod2 = 1e9 + 7;

    int dijkstra(int V, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(V);

        for (int i = 0; i < roads.size(); i++) {
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<int> ways(V, 0);
        vector<long long> weights(V, mod);

        weights[0] = 0;
        pq.push({0, 0});
        ways[0] = 1;

        while (!pq.empty()) {
            long long weight = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (const auto& it : adj[node]) {
                int curr = it.first;
                long long curr_weight = it.second;

                long long temp_weight = (curr_weight + weight) % mod;
                if (temp_weight < weights[curr]) {
                    weights[curr] = temp_weight;
                    ways[curr] = ways[node];
                    pq.push({weights[curr], curr});
                } else if (temp_weight == weights[curr]) {
                    ways[curr] = (ways[curr] + ways[node]) % mod2;
                }
            }
        }

        return ways[V-1];
    }

    int countPaths(int n, vector<vector<int>>& roads) {
        return dijkstra(n, roads);
    }
};
