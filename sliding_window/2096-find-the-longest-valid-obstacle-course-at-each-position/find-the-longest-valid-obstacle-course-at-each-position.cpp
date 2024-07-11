class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& arr) {
        vector<int> lis;
        vector<int> lislen(arr.size() , 0);
        for(int i = 0 ; i < arr.size() ; i++){
            int val = arr[i];
            if( lis.size() ==0 || lis.back() <= val){
                lis.push_back(val);
                lislen[i] = lis.size();
            }
            else{
                int ind = upper_bound(lis.begin() , lis.end()  , val) - lis.begin();
                lis[ind] = val;
                lislen[i] = ind+1;
            }
        }

        return lislen;
    }
};