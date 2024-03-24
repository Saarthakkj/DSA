class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int l = 0 ;
        int r = (arr.size() -  k)-1  ;  
        int ans = 0 ;
        int max = ans ; 
        for(int i = r+1 ; i < arr.size()  ; i++){
            ans+= arr[i]; 
        }
        max = ans ;
        r++ ;
        for(  ; r < arr.size()  ; r++) {
            // cout<< "ans is: "<< ans << endl ;
            // cout<< "l :" << l << " r is : " << r << endl;
            ans -=  arr[r] ; 
            ans += arr[l] ;
            if( ans > max){
                max = ans ; 
            }
            l++; 
        }

        return max ; 
    }
};