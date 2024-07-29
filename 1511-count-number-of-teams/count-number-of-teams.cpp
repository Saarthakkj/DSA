class Solution {
public:
    int numTeams(vector<int>& ratings) {
        int n = ratings.size();
        int teams = 0;
        for(int i = 1; i < ratings.size()-1 ; i++){
            int rate = ratings[i];
        //run a loop before this 'i'
            int j = i;
            int leftcnt = 0;
            while(j--)if(ratings[j] < rate)leftcnt ++;
            int rightcnt = 0;
            j = i;
            while(j++ and j <n) if(ratings[j] > rate)rightcnt++;

            int res1 = leftcnt*rightcnt ;
            int res2 = (i-leftcnt)*(n-1 -i - rightcnt);
            teams += (res1 + res2);
        }
        return teams;
    }
};