class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char , long long> count_T ;

        for(int i = 0 ;  i < t.size() ; i++){
            count_T[t[i]]++ ; 
        }

        unordered_map<char ,long long> count_s ;  

        int r = 0 ; 
        int l = 0 ;

        int have = 0 ; 
        int need = count_T.size(); 
        int len = INT_MAX ;  
        pair<int , int>ans ={-1 , -1}; 

        while(r < s.size()){
            count_s[s[r]]++ ; 
            //cout<< " " << count_s[s[r]]<< endl;
            //cout<< ": "<< s[r]<< endl;
            if( count_T.find(s[r]) != count_T.end() and count_s[s[r]] == count_T[s[r]]){
                have++ ; 
            }
            //cout<< "l is : "<< l << "r is : "<< r <<  "have : "<< have  << endl;
            while(have == need){
                //cout<< "(while)l is : "<< l << "r is : "<< r <<endl;
                if(len > (r-l+1)){
                    len = (r-l+1) ;
                    ans.first =  l;
                    ans.second = r ; 
                }
                count_s[s[l]]-- ; 

                if(count_T.find(s[l]) != count_T.end() and count_T[s[l]] > count_s[s[l]]){
                    have--  ;
                }
                l++ ; 
            }
            r++ ; 
        }

        if(ans.first ==-1 and ans.second  == -1){
            return ""; 
        }
        return s.substr(ans.first , (ans.second - ans.first +1)) ; 
    }
};