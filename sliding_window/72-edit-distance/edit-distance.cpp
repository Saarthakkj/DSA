class Solution {
public:
    int ans = 1e9+7;
    int dp[501][501];
    int f(int i , int j , string s1 , string s2){
        if(i < 0 and j < 0){
            return 0;
        }
        if(i < 0){
            return j+1;
        }
        if(j < 0){
            return i+1;
        }

        //if matched: 
        if(s1[i] == s2[j]){
            return f(i-1 , j-1  , s1 , s2);
        }

        //if notmatched
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ins = 1 + f(i  , j-1 , s1 , s2);
        int del = 1 + f(i-1 , j, s1 , s2);
        int repl = 1+ f(i-1 , j-1 , s1 , s2);

        int temp = min(repl , del);
        ans =min(temp ,ins);
        dp[i][j] = ans;

        return ans;
    }

    int minDistance(string word1, string word2) {
        //int dp[word1.size()][ word2.size() ];
        memset(dp , -1 , sizeof(dp));
        return f(word1.size()-1 , word2.size()-1 , word1 , word2);

    }
};