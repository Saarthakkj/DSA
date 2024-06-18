#define ll long long int
class Solution {
public:

    long long maximumTotalDamage(vector<int>& power) 
    {
       map<ll , ll> mpp;
       for(int i = 0 ; i < power.size(); i++){
            mpp[power[i]]++;
       }

       unordered_map<int , ll> dp;
       ll ans = 0;
       //dp[0] = power[0]*mpp[power[0]];
       ll backele = 0 , prevele = 0;
       for(auto [ele , fr] : mpp){
            //int ele = power[i];
            auto it = mpp.lower_bound(ele-2);
            if(it != mpp.begin()){
                --it;
                backele = it->first;
            }
            //cout<< " ele : "<< ele << " prevele  :"<< prevele << " backele : "<< backele ;
            dp[ele] = max(dp[prevele], fr*ele + dp[backele] );
            prevele= ele;
            //cout<< " dp[ele] : "<< dp[ele]<< endl;
            ans = max(ans , dp[ele]);
       }

       return ans;
    }
};