class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        long long ans=0;
        int rows[1001];
        int cols[1001];

        memset(rows, 0, sizeof(rows)); 
        memset(cols , 0 , sizeof(cols));
        int max_row = grid.size();
        int max_col = grid[0].size();
        //vector<vector<int>> vis(max_row , vector<int>(max_col , 0));
        for(int i = 0 ; i < max_row ; i++){
            for(int j = 0 ; j < max_col ; j++){
                rows[i]+= grid[i][j];
                cols[j]+=grid[i][j];
            }
        }

        for(int i = 0 ; i < max_row ; i++){
            for(int j= 0 ; j <max_col ; j++){
                if(grid[i][j]){
                    ans+=(( rows[i]-1LL)* (cols[j]-1LL));
                }
            }
        }


        return ans;
    }
};