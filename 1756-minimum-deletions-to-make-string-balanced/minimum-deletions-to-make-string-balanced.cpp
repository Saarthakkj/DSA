class Solution {
public:
    int minimumDeletions(string s) {
        int res = 0;
        int cnt = 0;
        for(char c : s){
            if(c =='b'){
                cnt++;
            }
            else if(cnt) {
                cnt--;
                res++;
            }
        }
        return res;
    }
};