class Solution {
public:
    int trap(vector<int>& v) {
        //space complexity  = 2N

        int water = 0 ;
        int l_max =0 ; 
        int r_max =  0 ;
        int l = 0;
        int r = v.size()-1 ;
        while(l<=r){
            if(v[l] <= v[r]){
                if(v[l] >= l_max ){
                    l_max = v[l];
                }
                else{
                    water+=(l_max -v[l]);
                }
                l++;
            }
            else{
                if(v[r] >= r_max){
                    r_max = v[r];
                }
                else{
                    water+=(r_max - v[r]);
                }
                r--;
            }
        }
        return water;
    }
};