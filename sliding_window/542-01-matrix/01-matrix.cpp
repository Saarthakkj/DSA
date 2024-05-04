class Solution {
private: 
    struct cell{
        int row ;
        int col ;
        int dist ;
        cell(int i , int j  , int k ){
            row = i;
            col = j ;
            dist = k ; 
        }
    };
public:
    int d_row[4] = {-1 , 0 , +1 , 0}; 
    int d_col[4] = {0 , 1 , 0 , -1}; 
    queue<cell> q ; 

    vector<vector<int>> updateMatrix(vector<vector<int>>& graph) {
        int max_row = graph.size() ;
        int max_col = graph[0].size()  ;

        vector<vector<int>> visited(max_row, vector<int>(max_col, 0)); // Initialize visited with proper dimensions
        vector<vector<int>> res(max_row, vector<int>(max_col, 0)); // Initialize res with proper dimensions

        for(int row = 0 ; row < max_row ; row++ ){
            for(int col = 0 ; col < max_col ; col++){
                if(graph[row][col] == 0){
                    q.push(*new cell(row , col , 0)) ;
                    visited[row][col] = 1 ; 
                }
            }
        } 

        //queue has all the 1s in it. 

        //bfs-algorithm
        while(!q.empty()){
            cell c = q.front() ; 
            q.pop() ;

            int row = c.row ;
            int col = c.col ; 
            int dist = c.dist ;
            //visited[row][col] = 1;
            res[row][col] = dist; 

            res[row][col] = dist;

            //search for '1' in the array : 
            for(int i = 0 ; i< 4; i++){
                int n_row = row+d_row[i] ; 
                int n_col = col + d_col[i] ; 
                if(n_row >=0 and n_row < max_row and n_col < max_col and n_col >=0 and visited[n_row][n_col] == 0){
                    q.push(*new cell(n_row , n_col , dist+1) ); 
                    visited[n_row][n_col]= 1;
                }
            }
        }

        return res;
    }
};
