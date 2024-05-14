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

            for(auto it = st.begin(); it != st.end();) {
                string shabd = *it; 
                int count = 0;
                for(int j = 0; j < word.size(); j++) {
                    if(word[j] != shabd[j]) {
                        count++; 
                    }
                    if(count > 1) {
                        break;
                    }
                }
                //cout<< "shabd: "<< shabd << " word: "<< word << " count : "<< count << endl;
                if(count == 1) {
                    q.push(make_pair(*it, ans + 1)); 
                    //cout << "*it: " << *it << endl;
                    auto next_it = next(it) ; 
                    // Increment the iterator before erasing
                    // Erase the element
                    st.erase(it);
                    it = next_it; 
                } else {
                    // Move to the next value
                    ++it;
                }
            }
        }
        return 0 ; 
    }
};