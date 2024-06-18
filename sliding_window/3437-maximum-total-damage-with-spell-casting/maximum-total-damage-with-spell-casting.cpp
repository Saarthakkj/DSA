class Solution {
public:

    long long maximumTotalDamage(vector<int>& power) 
    {
        map<long long,long long> m;
        for(int i : power)
            m[i]++;
        vector<int> arr;
        for(auto a: m)
            arr.push_back(a.first);
        // sort(arr.begin(),arr.end());
        vector<long long> dp(arr.size(),0),v(arr.size(),-1);

        dp[arr.size()-1] = (arr.back()*m[arr[arr.size()-1]]);

        for(int i = arr.size()-1; i >= 0; i--)
        {
            int ind = arr.size();
            for(int j = i; j < arr.size(); j++)
            {
                if(arr[j] > arr[i]+2)
                {
                    ind = j;
                    break;
                }
            }

            long long a = 0,b = 0;
            if(ind < arr.size())
                a = (arr[i]*m[arr[i]]) + dp[ind];
            else
                a = (arr[i]*m[arr[i]]);
            if(i+1 < arr.size())
                b = dp[i+1];
            dp[i] = max(a,b);

        }
        // long long ans = helper(arr,0,m,dp,v);
        return dp[0];
    }
};