class Solution {
public:   
    vector<vector<int>> subsets(vector<int>& nums) {
        int total =  1<< nums.size(); 
        vector<vector<int>> ans;
        for(int mask = 0 ; mask < total  ; mask++ ){
            vector<int> set; 
            for(int i = 0 ; i < nums.size() ; i++){
                if(mask & (1<<i)){
                    set.push_back(nums[i]) ;
                }
            }
            ans.push_back(set) ;
        }

        return ans;
    }
};