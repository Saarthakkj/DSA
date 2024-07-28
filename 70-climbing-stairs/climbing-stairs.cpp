class Solution {
public:
    int dp[46] ;
    int func(int n){
        if(n==0) return 1;
        if(n <0) return 0;
        if(dp[n] != 0) return dp[n];
        int left = func(n-1);
        int right = func(n-2);
        return dp[n]= left+right;
    }
    int climbStairs(int n) {
        memset(dp , 0 , sizeof(dp));
        return func(n);
    }
};