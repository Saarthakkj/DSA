class Solution {
public:
    int maximumLength(vector<int>& nums) {
        vector<int> same(2 , 0) , diff(2 , 0);
        for(int i = 0 ; i < nums.size() ; i++){
            int currRem = nums[i]%2;
            same[currRem] = same[currRem]+1;
            diff[currRem] =  1 + diff[1 ^ currRem];
        }

        return max({same[0] , same[1] , diff[0] , diff[1]});
    }
};