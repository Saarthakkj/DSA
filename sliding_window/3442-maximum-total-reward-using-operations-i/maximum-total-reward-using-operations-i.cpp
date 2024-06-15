class Solution {
public:
    int dp[2001][4000];
    int ans = 0 ;
    int func(int i , int x , vector<int>& arr){
        if(i == arr.size()){
            return x;
        }

        if(dp[i][x] != -1){
            return dp[i][x];
        }
        int res = -1;


        //else if it is -1
        if(arr[i] > x){
            int incl = func(i+1 , x+arr[i] , arr);
            int excl = func(i+1 , x , arr);
            res = max(incl , excl);
        }
        else{
            res = func(i+1 , x , arr);
        }
        dp[i][x] = res;
        //cout<< " "<<  res << endl;

        ans = max(ans , res);
        return res  ;
    }
    int maxTotalReward(vector<int>& arr) {
        set<int> s;
        memset(dp, -1, sizeof(dp));
        for(int i =0 ; i < arr.size() ; i++) {
            s.insert(arr[i]);
        }

        vector<int> v;
        for(auto it = s.begin() ; it != s.end() ; ++it){
            v.push_back(*it);
            //s.erase(*it);
        }

        sort(v.begin() , v.end());

        func(0 , 0  , v);
        //cout<< " ans : "<< ans ;
        return ans;

    }
};

