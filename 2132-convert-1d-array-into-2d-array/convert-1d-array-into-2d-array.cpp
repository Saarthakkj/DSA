class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> res;
        vector<int> temp;
        if(n*m != original.size()){
            return vector<vector<int>>();
        }
        for(int i =0 ; i < original.size() ; i++){
            if(i%(n) == 0 and i != 0){
                res.push_back(temp);
                temp = {};
            }
            temp.push_back(original[i]);
        }
        res.push_back(temp);
        return res;
    }
};