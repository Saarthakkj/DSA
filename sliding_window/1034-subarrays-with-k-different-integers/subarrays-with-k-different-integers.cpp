class Solution {
public:
    int func(vector<int>& arr , int k ){
        if(k == 0 ){
            return 0 ; 
        }
        int l = 0 ;
        int r= 0 ; 
        int uniq_c = 0 ;
        int ans = 0 ;
        map<int , int> mpp  ;
        while(r < arr.size()){
            if(mpp[arr[r]] ==  0){
                uniq_c ++ ; 
                while(uniq_c > k and l < r){
                    if(--mpp[arr[l]] == 0 ){
                        uniq_c --; 
                    }
                    l++ ; 
                }
            }
            //cout<< "l is:"<< l << " r is :"<< r << endl;
            mpp[arr[r]] ++ ; 
            ans += (r-l+1) ; 
            r++ ; 
        }

        return ans ; 
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return func(nums , k )  - func(nums , k-1);
    }
};