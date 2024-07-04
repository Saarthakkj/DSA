class Solution {
public:
    static bool comp(const string& a , const string& b){
        return (a.length() < b.length());
    }
    int maxPalindromesAfterOperations(vector<string>& words) {
        map<int , int> freq; 
        for(auto s :  words){
            for(auto  it : s){
                freq[it - 'a']++; 
            }
        }

        //now move to the strings and make palindromes
        int pal = 0;
        sort(words.begin() , words.end() , comp);
        int even = 0;
        int odd = 0 ;
        for(auto it : freq){
            even += (it.second/2);
            odd+= (it.second%2);
        }
        for(auto word : words){
            //cout<< "even: "<<  even << " odd:  "<< odd << endl;
            if(word.length()%2){
                //if word length == odd
                if(odd){
                    odd--;
                }
                else{
                    even--;
                    odd++; 
                }
            }
            if(even < word.length()/2){
                break;
            }
            even -= word.length()/2;
            pal++;
        }

        return pal;
    }
};