class Solution {
public:
    int numberOfSubstrings(string s) {
        int l  , r = 0 ;
        vector<int> abc(3 , 0);
        int ans = 0;
        while( r < s.size()){
            abc[s[r] - 'a']++ ; 
            while(abc[0] >=1 and abc[1] >=1 and abc[2] >=1){
                ans+= (s.size() - r);
                abc[s[l] - 'a']-- ;
                l++ ; 
            }
            r++ ; 
        }
        return ans ; 
    }
};