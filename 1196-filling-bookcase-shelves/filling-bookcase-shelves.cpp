class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf) {
        int n = books.size();
        vector<int> dp(n+1 , INT_MAX);
        dp[0]=0;
        for(int i = 1 ; i <=n ; i++){
            int width =0;
            int height =0;
            for(int j = i ; j >0 ; j--){
                width += books[j-1][0];
                if(width > shelf)break;
                height = max(height , books[j-1][1]);
                dp[i] = min(dp[i] , dp[j-1] + height);
                //cout<< "dp : "<< dp[i]<< endl;
            }
        }
        return dp[n];
    }
};