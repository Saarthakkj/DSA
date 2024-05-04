#include <vector>

class Solution {
public:
    int d_row[4] = {-1 , 0 , +1 , 0}; 
    int d_col[4] = {0 , 1 , 0 , -1}; 

    bool dfs(int row , int col , vector<vector<int>>& graph, vector<vector<int>>& visited, int max_row, int max_col){
        // if(row == max_row or row == 0 or col == 0 or col == max_col ){
        //     //cout<< "row : "<< row << " col : "<< col << endl;
        //     return true;
        // }

        visited[row][col] = 1;

        for(int i = 0; i < 4; i++){
            int n_row = row + d_row[i];
            int n_col = col + d_col[i]; 

            if(n_row >= 0 and n_col >= 0 and n_row < max_row and n_col < max_col and visited[n_row][n_col] == 0 and graph[n_row][n_col] == 1){
                dfs(n_row, n_col, graph, visited, max_row, max_col) ; 
            }
        }

        return false; // Added return statement as the function is supposed to return a bool value
    }

    int numEnclaves(vector<vector<int>>& graph) {
        int max_row = graph.size(); 
        int max_col = graph[0].size();
        // Using vector of vectors instead of a 2D array
        int ans = 0; 
        vector<vector<int>> visited(max_row, vector<int>(max_col)); 

        for(int row = 0; row < max_row; row++){
            int col = 0 ;  
            if(graph[row][col] == 1 and visited[row][col] == 0 ){
                dfs(row, col, graph, visited, max_row, max_col); 
                //have to append this on something
            }
        }
        for(int col = 0; col < max_col; col++){
            int row = 0 ;  
            if(graph[row][col] == 1 and visited[row][col] == 0 ){
                dfs(row, col, graph, visited, max_row, max_col); 
                //have to append this on something
            }
        }
        for(int row = 0; row < max_row; row++){
            int col = max_col-1 ;  
            if(graph[row][col] == 1 and visited[row][col] == 0 ){
                dfs(row, col, graph, visited, max_row, max_col); 
                //have to append this on something
            }
        }
        for(int col = 0; col < max_col ; col++){
            int row = max_row-1 ;  
            if(graph[row][col] == 1 and visited[row][col] == 0 ){
                dfs(row, col, graph, visited, max_row, max_col); 
                //have to append this on something
            }
        }


        for(int i = 0 ; i < max_row ; i++){
            for(int j = 0 ; j < max_col ; j++){
                if(graph[i][j] == 1 and visited[i][j] == 0){
                    //cout<< " i :"<< i << "j :"<< j << endl;
                    ans++ ;
                }
                // else{
                //     //cout<< "i :"<< i << " j is : "<< j << endl;
                // }
            }
        }

        return ans; 
    }
};
