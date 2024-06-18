class Solution {
public:
    int length = -1;
    int dp[2501][2502];
    int f(int i ,int prev,  vector<int>&arr){
        if(i == arr.size()){
            return 0;
        }

        //pick-not pick
        //cout<< "prev+1  ;"<< prev ;
        if(dp[i][prev+1] != -1){
            return dp[i][prev+1];
        }

        //not pick  : 
        int notpick = 0 + f(i+1 , prev , arr);

        int pick  = 0;
        if( prev == -1 or arr[i] > arr[prev]){
            pick = 1 + f(i+1 , i , arr);
        }

        length = max(pick ,notpick);

        return dp[i][prev+1] = length; 
    }
    int lengthOfLIS(vector<int>& arr) {
        memset(dp , -1 , sizeof(dp)) ; 
        return f(0 , -1, arr );
    }
};