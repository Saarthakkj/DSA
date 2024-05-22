class Solution {
public:
    int d_row[4] = {-1 , 0 , 1 , 0} ;
    int d_col[4] = {0 , 1 ,0 ,-1 } ;
    //int min_diff = INT_MAX ; 

    int dijkstra(int i , int j  , vector<vector<int>>& graph , vector<vector<int>>& diff ){ // }, 
        int max_row = graph.size() ; 
        int max_col = graph[0].size() ; 

        priority_queue<pair<int, pair<int, int>>,
                    vector<pair<int, pair<int, int>>>,
                    greater<pair<int, pair<int, int>>>>
            pq;

        pq.push({0 , {0 , 0}}) ;
        diff[i][j] = 0; 
        //length is the third element in the queue

        while(!pq.empty()){
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            int curr_diff = pq.top().first;

            pq.pop();

            if(row == max_row-1 and col == max_col-1){
                return curr_diff; 
            }

            for(int k = 0 ; k < 4 ; k++ ){
                int n_row = d_row[k] + row; 
                int n_col =  d_col[k] + col  ;

                //int new_effort = max( abs(graph[row][col] - graph[n_row][n_col]) ,  curr_diff) ;

                if (n_row >= 0 && n_row < max_row && n_col >= 0 && n_col < max_col) {
                    int new_effort = max(abs(graph[row][col] - graph[n_row][n_col]), curr_diff);

                    if (new_effort < diff[n_row][n_col]) {
                        pq.push({new_effort, {n_row, n_col}});
                        diff[n_row][n_col] = new_effort;
                    }
                }
            }

        }

        return  -1; 
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int max_row = heights.size();
        int max_col = heights[0].size();
        vector<vector<int>> diff(max_row, vector<int>(max_col, INT_MAX));

        return dijkstra(0, 0, heights, diff);

        // for(int i = 0 ; i < diff.size() ; i++ ){
        //     for(auto it : diff[i]){
        //         cout<< " "<< it;
        //     }
        //     cout<< endl;
        // }
    }
};