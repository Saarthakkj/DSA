class Solution {
public:
    bool isValid(string s) {
        char c = ' ';
        stack<char> s1;
        int i = 0;
        while(i<s.size()){
            c = s[i] ; 
            if(c == '{' or c == '[' or c == '('){
                //cout<< "here";
                s1.push(c);
            }
            else{
                
                //cout<< "c : "<< c << " s1.top() : "<< s1.top() << endl;
                switch (c){
                    case ')':
                        if(!s1.empty() and s1.top() == '(' ){
                            s1.pop();
                            break;
                        }
                        else{
                            return false;
                        }
                    case '}':
                        if(!s1.empty() and s1.top() == '{' ){
                            s1.pop();
                            break;
                        }
                        else{
                            return false;
                        }
                    case ']':
                        if(!s1.empty() and s1.top() == '[' ){
                            s1.pop();
                            break;
                        }
                        else{
                            return false;
                        }
                    default : 
                        cout<< "hey ";
                        return false;
                }
            }
            i++;
        }
        if(s1.empty()){
            return true;
        }
        return false;
    }
};