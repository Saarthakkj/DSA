class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int dp[1001];
        dp[0] = 0;
        dp[1] = 0;
        int n = cost.size();
        //cost.push_back(n);
        for(int i = 2 ; i <= n ; i++){
            dp[i] = min(dp[i-1]+cost[i-1] ,cost[i-2]+dp[i-2]);
        }
        return dp[n];
    }
}; 