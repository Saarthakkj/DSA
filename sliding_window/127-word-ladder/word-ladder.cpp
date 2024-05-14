class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //vector<string> graph ; 
        //map< string , int> words; 
        queue<pair<string , int>> q ; 

        q.push(make_pair(beginWord , 1)) ; 
    
        
        unordered_set<string> st(wordList.begin(), wordList.end());

        if(st.count(endWord) == 0){
            return 0 ; 
        }

        st.erase(beginWord) ; 



        //int ans = 1;
        int ans = 0;

        while(!q.empty()){
            pair<string , int> pair = q.front() ; 
            int ans =  pair.second;
            string word = pair.first;
            q.pop() ; 

            if(word == endWord){
                return ans;
            }
            // ans++ ; 

            //set length approach fails and set length can be very large and we might get count ==1 element in last 
            for(int i = 0 ; i < word.size() ; i++){
                char original = word[i] ; 
                for(char c = 'a' ; c <= 'z' ; c++){
                    word[i] = c;
                    if(st.count(word) !=0 ){
                        st.erase(word); 
                        q.push(make_pair(word , ans+1)) ;
                    }
                }
                word[i] =  original   ;
            }
        }
        return 0 ; 
    }
};