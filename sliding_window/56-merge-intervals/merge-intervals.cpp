class Solution {
public:
    bool static comparator(const vector<int>& a , const vector<int>& b){
        return a[0] < b[0]  ;
    }
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        vector<vector<int>> ans ; 
        sort(arr.begin() , arr.end() , comparator) ; 
        int prev_start = arr[0][0] ; 
        int prev_end = arr[0][1] ; 

        ans.push_back({{prev_start , prev_end}}) ; 

        for(int i = 1 ; i < arr.size() ; i++){
            int curr_start = arr[i][0] ; 
            int curr_end = arr[i][1] ; 

            if(curr_start <= prev_end and curr_end > prev_end){
                //cout<< "prev start : "<< prev_start << " curr end "<< curr_end ;
                vector<int> temp = {prev_start , curr_end} ; 
                prev_end = curr_end ;
                ans.pop_back() ; 
                ans.push_back(temp) ; 
            }
            else if(curr_start > prev_end){
                vector<int> temp = {curr_start , curr_end} ; 
                ans.push_back(temp) ; 
                prev_start = curr_start ;
                prev_end = curr_end ; 
            }
        }

        return ans; 
    }
};