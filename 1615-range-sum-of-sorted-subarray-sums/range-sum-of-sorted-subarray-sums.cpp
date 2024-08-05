class Solution {
public:
    const int mod = 1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int new_len = n*((n+1)/2);
        vector<int> v;
        for(int i = 0 ; i < n; i++){
            int sum = nums[i];
            v.push_back(sum);
            for(int j = i+1 ; j <n ; j++){
                sum+= nums[j];
                v.push_back(sum);
            }
        }
        sort(v.begin() , v.end());
        int res = 0;
        for(int ind = left-1 ; ind <= right-1 ; ind++){
            res+= v[ind];
            res %= mod;
        }

        return res%mod;
    }
};