class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans ; 
        int new_start = newInterval[0] ; 
        int new_end = newInterval[1] ; 

        for(int i = 0 ; i < intervals.size() ; i ++){
            int start = intervals[i][0] ; 
            int end = intervals[i][1] ; 

            if( start >  new_end ){
                //cout<< " hey :"<< start << " new end " << new_end ; 
                vector<int> temp = {new_start , new_end} ; 

                ans.push_back(temp) ; 
                for(int j = i ; j < intervals.size() ; j++){
                    ans.push_back(intervals[j]) ;
                }

                return ans ;
            }
            else if(end  < new_start){
                ans.push_back(intervals[i]) ; 
            }
            else{
                //cout<< "start : "<< intervals[i][0] << " end : " << intervals[i][1]  ;
                new_start = min(new_start , start) ; 
                new_end = max(new_end , end) ; 

                //cout<< "new start : "<< new_start << " new end " << new_end ; 
            }
        }

        vector<int> temp = {new_start , new_end} ; 

        ans.push_back(temp)  ;
        return ans ; 

    }
};