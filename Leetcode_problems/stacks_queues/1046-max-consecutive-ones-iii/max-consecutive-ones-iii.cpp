class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0 ;
        int r = 0 ;
        int n  =  nums.size() ;
        int temp =  0 ; 
        int len = 0 ;
        while(r<n){
            if(!nums[r]){
                temp++ ; 
                
                //len = max(len , r-l+1) ;
            }
            while(temp> k){
                if(nums[l] ==0 ){
                    temp--;
                }
                l++;
            }
            len = max(len , r-l+1);
            //cout<< " l : "<< l << " r : "<< r << "len is : "<< len<< endl;
            r++;
        }
        return len ; 
    }
};