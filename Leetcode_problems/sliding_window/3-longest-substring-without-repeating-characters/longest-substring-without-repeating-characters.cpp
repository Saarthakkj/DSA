class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi =  0;
        int l = 0 ; 
        int r =  0 ; 
        set<char> sett ; 
        
        for(int r = 0 ; r < s.size() ; r++){
            if(sett.find(s[r]) != sett.end()){            
                //shorten the current string to not contain any duplicate elements
                while(sett.find(s[r]) != sett.end() && l<r){
                    sett.erase(s[l]);
                    l++;
                }
            } 
            sett.insert(s[r]);
            maxi = max(r-l+1 , maxi); 
            //cout<< " inserted here : "<< s[r]<< endl;
        }
        //maxi = max(maxi , r-l);
        return maxi  ;
    }
};