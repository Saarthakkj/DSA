class Solution {
public:
    bool static comparator(const vector<int> &a , const vector<int>& b){
        return a[0] < b[0] ; //change to a[0]  > b[0]  for descending order
    }
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        sort(arr.begin() , arr.end() , comparator) ; 
        int res = 0 ;
        int end = arr[0][1] ; 
        for(int i =1; i < arr.size() ; i++){
            if(arr[i][0] >= end){
                end = arr[i][1] ; 
            }
            else{
                res ++ ; 
                end = min(end , arr[i][1]) ; 
            }
        }

        return res; 
    }
};