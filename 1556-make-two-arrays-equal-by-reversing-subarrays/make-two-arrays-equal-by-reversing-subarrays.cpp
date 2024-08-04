class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int , int> f;
        for(auto ele : arr){
            f[ele]++;
        }
        for(auto ele : target){
            f[ele]--;
        }
        for(auto ele : f ){
            if(ele.second != 0)return false;
        }
        return true;
    }
};