class Solution { 

    int min_length = INT_MAX ; 
    //bool reached = false;
public:
    int d_row[8] = {-1 , 0 , 1 , 0 , -1 , 1, 1 , -1};
    int d_col[8] = {0 , 1 , 0 , -1 , 1 , -1 , 1 , -1} ;

    int bfs(int i , int j  , vector<vector<int>>& graph , vector<vector<int>>& visited ){
        int n = graph.size() ; 

        queue<pair<pair<int, int> , int>> q; 

        q.push(make_pair(make_pair(i , j) , 1)) ;
        visited[i][j]++; 
        //length is the third element in the queue

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int length = q.front().second;

            q.pop();

            if(row == n-1 and col == n-1)
            {
                //reached = true;
                //cout<< "here";
                min_length = length ;
                return min_length ;
            }

            for(int k = 0 ; k <= 7 ; k++ ){
                int n_row = d_row[k] + row; 
                int n_col =  d_col[k] + col  ;

                if(n_row < n and n_row >= 0 and n_col < n and n_col >= 0 and visited[n_row][n_col] == 0 and graph[n_row][n_col] == 0 )
                {
                    q.push(make_pair(make_pair(n_row , n_col) , length+1)) ;
                    visited[n_row][n_col]++ ; 
                }
            }

        }

        return -1 ; 
    }


    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size() ; 
        vector<vector<int>> visited(n, vector<int>(n, 0));
        if(grid[0][0] == 1){
            return -1;
        }
        return bfs(0 , 0 , grid , visited)  ;
        // //cout<< "reached : " << reached;
        // if(!reached){
        //     return -1;
        // }

        
        // //cout<< "ans : "<< ans << endl;
        // return min_length;
    }
};
