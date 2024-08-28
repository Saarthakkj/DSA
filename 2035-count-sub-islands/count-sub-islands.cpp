class Solution {
public:
    int d_row[4] = {-1 , 1 , 0 , 0};
    int d_col[4] = {0 , 0 , 1 , -1};
    bool dfs( int i , int j , vector<vector<int>>& grid , vector<vector<int>>& vis , vector<vector<int>>& grid2){
        
         int n = grid.size();
        int m = grid[0].size();
        //cout<< s.size()<< endl;

        int ans = 1;
        if(i>=0 and j>=0  and i < n and j < m and !vis[i][j] and grid[i][j]){
            if(grid2[i][j] == 0){
                return 0;
            }
            vis[i][j] = 1;
            for(int k = 0 ; k < 4 ; k++){
                int n_row = d_row[k]+i;
                int n_col = d_col[k]+j;

                ans&= dfs(n_row , n_col , grid ,vis , grid2);
            }
            
        }
        else{
            
            return 1;
        }
       
        
        return ans;

    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size(); 
        int res=  0;
        vector<vector<int>> vis(n  , vector<int>(m , 0));
        for(int i = 0 ; i < n ; i++){
            for(int j= 0 ; j < m ; j++){
                if(grid2[i][j] == 0) continue;
                if(vis[i][j] == 0){
                    //set<pair<int ,int>> s;
                    res+=dfs(i , j  , grid2 , vis , grid1);
                }
            }
        }
        return res;
    }
};