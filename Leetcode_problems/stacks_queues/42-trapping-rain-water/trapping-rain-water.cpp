class Solution {
public:
    int trap(vector<int>& v) {
        int water = 0 ;
        vector<int> prefix; 
        int l_max = 0;
        for(int i = 0 ; i< v.size()-1 ; i++){
            if(v[i] > l_max){
                l_max= v[i];
            }
            //cout<< "l_max : " << l_max << endl;
            prefix.push_back(l_max);
        }

        vector<int> suff ; 
        int r_max  = 0 ;
        for(int i =  v.size()-1 ; i>=0 ; i--){
            if(v[i] > r_max ){
                r_max = v[i];
            }
            //cout<< "r_max : " << r_max << endl;
            suff.insert(suff.begin() ,r_max);
        }

        for(int i = 0 ; i < v.size()-1 ; i++){
            int temp = v[i] ;
            water+= min(prefix[i] , suff[i]) - temp;
        }

        return water;
    }
};