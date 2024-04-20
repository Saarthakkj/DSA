// #include <cstdlib>
class Solution {
public:
    bool checkValidString(string s) {
        stack<pair<char , int> > f; //for forward bracket
        stack<pair<char , int> > b ; //for backward bracket
        stack<pair<char, int> > a ;  // for aestrick 
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '('){
                f.push({s[i] , i}) ; 
            }
            else if(s[i] == ')'){
                b.push({s[i] , i}) ; 
                if(f.empty()){
                    if(a.empty()){
                        // cout<< "f.size() : "<< f.size()  << " a.size(): "<< a.size() ;
                        // cout<< " returning false here i is: " << s.size() -i; 
                        return false;
                    }
                    else{
                        a.pop() ; 
                        b.pop();
                    }
                }else{
                    f.pop() ;
                    b.pop() ; 
                }
                
            }
            else{
                a.push({s[i] , i}) ; 
            }
        }
        
        while(!f.empty()){
            if(a.empty() and !f.empty()){
                return false;
            }
            //cout<< "f.empty: "<< f.empty() <<" a empty: "<< a.empty();
            if(f.top().second < a.top().second){
                //cout<< "here is f and a"<< endl ;
                f.pop() ;
                a.pop() ;
            }else{
                return false;
            }
        }
        //cout<< "f size: " << f.size() << " b.size(): "<< b.size() << " a size:  "<< a.size() ;
        // int temp =  f.size() - b.size() ;
        return true ;
    }
};
