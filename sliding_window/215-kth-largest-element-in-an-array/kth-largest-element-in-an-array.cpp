class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        map<int , int> mpp  ;
        int maxi =  INT_MIN ; 
        int mini = INT_MAX ; 
        for(int i = 0 ; i < nums.size() ; i++){
            //cout<< "nums[i] : "<< nums[i] << endl ;
            mpp[nums[i]] ++ ; 
            maxi = max(maxi , nums[i]) ;
            mini = min( mini , nums[i]) ;
        }

        //cout<< "mpp size: "<< mpp.size() ; 

        for(int i = maxi ; i >= mini  ; i--){
            k-= mpp[i] ; 
            //cout<< "i: "<< i <<  " mpp[i] : "<< mpp[i] << " k is: "<< k << endl;
            if(k <= 0) {
                return i  ;
            }
        }
        return -1 ; 
    }
};