class Solution {
public:
    int func(vector<int>& nums , int goal ){
        if(goal <0){
            return 0 ; 
        }
        int l = 0;
        int r = 0;
        int sum = 0;
        int ans = 0 ;
        int n  =  nums.size(); 

        while(r < n){
            sum += nums[r];
            //cout<< " l is : "<< l << "r is : "<< r<<endl;
            while(sum > goal ){
                sum -= nums[l];
                l++ ; 
            }
            ans += (r-l+1); 
            r++; 
        }
        return ans ; 
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return func(nums , goal) - func(nums , goal-1) ;
    }
};