class Solution {
public:
    //int mod = 1e9 + 7;
    long long countCompleteDayPairs(vector<int>& arr) {
        long long count =0  ;
        map<int ,int> mpp;
        for(int i = 0 ; i < arr.size() ; i++){
            count+= mpp[(24 - arr[i]%24)%24];
            mpp[arr[i]%24]++;
        }
        
        return count;
    }
};