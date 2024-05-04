class Solution {
public:
    int d_row[4]= {-1 , 0 , 1 ,0 };
    int d_col[4] = {0 , 1 , 0 , -1} ; 

    void dfs(vector<vector<char>>& graph , vector<vector<int>>& visited , int row , int col){
        int max_row = graph.size() ;
        int max_col = graph[0].size() ; 

        for(int i = 0 ; i < 4; i++){
            int n_row = d_row[i] + row ; 
            int n_col = d_col[i] + col;  

            if(n_row < max_row and n_row >=0 and n_col < max_col and n_col >=0 and graph[n_row][n_col] == 'O' and visited[n_row][n_col] == 0){
                visited[n_row][n_col] = 1 ; 
                dfs(graph , visited , n_row , n_col)  ;
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int max_row = board.size() ;
        int max_col = board[0].size() ; 

        vector<vector<int>> visited(max_row, vector<int>(max_col, 0)); 

        for(int row = 0 ; row < max_row ; row++){
            int col = 0 ;
            if(board[row][col] == 'O' and visited[row][col] == 0 ){
                cout<< "row : "<< row << "col: "<< col << endl;
                visited[row][col] = 1; 
                dfs(board , visited , row , col);
            }
        }
        for(int row = 0 ; row < max_row ; row++){
            int col = max_col-1 ;
            if(board[row][col] == 'O' and visited[row][col] == 0){
                visited[row][col] = 1; 
                cout<< "row : "<< row << "col: "<< col << endl;
                dfs(board , visited , row , col);
            }
        }
        for(int col = 0 ; col < max_col ; col++){
            int row = 0 ;
            if(board[row][col] == 'O' and visited[row][col] == 0){
                visited[row][col] = 1; 
                cout<< "row : "<< row << "col: "<< col << endl;
                dfs(board , visited , row , col);
            }
        }
        for(int col = 0 ; col < max_col ; col++){
            int row = max_row-1 ;
            if(board[row][col] == 'O' and visited[row][col] == 0){
                visited[row][col] = 1; 
                cout<< "row : "<< row << "col: "<< col << endl;
                dfs(board , visited , row , col);
            }
        }

        for(int row = 0 ; row < max_row ; row++){
            for(int col = 0 ; col < max_col ; col++){
                if(board[row][col] == 'O' and visited[row][col] == 0){
                    board[row][col] = 'X' ; 
                }
            }
        }

        return ;

    }
};