class Solution {
public:
    int func( vector<int>& arr ,  int k ){
        map<int,int> mpp ; 
        int l = 0 ;
        int r  = 0 ;
        int ans= 0  ; 
        int oddcount = 0 ;
        for( ; r < arr.size() ; r++) {
            if(arr[r]%2){
                //odd number 
                oddcount ++ ; 
                while(oddcount >k){
                    if(arr[l] %2) { 
                        oddcount-- ; 
                    }
                    l++ ; 
                }
                mpp[r] =  oddcount ; 
            }
            ans+= (r-l+1);
            //cout<< "r : "<< r << " l : "<< l << endl;
        }
        //cout<< "ans : "<< ans << endl;
        return ans ;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return func(nums , k) - func(nums , k-1) ;
    }
};