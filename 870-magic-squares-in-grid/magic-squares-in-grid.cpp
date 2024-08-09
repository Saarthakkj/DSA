class Solution {
public:
    bool check(int startr , int startc , int endr , int endc , vector<vector<int>>& grid){
        set<int> s;
        int rowsum =-1;
        for(int i = startr ; i < endr ; i++){
            int temprow =0;
            for(int j = startc ; j < endc ; j++){

                if(grid[i][j] > 9 or grid[i][j] == 0) return false;
                temprow +=grid[i][j];
                s.insert(grid[i][j]);
            }
            if(rowsum==-1) rowsum = temprow;
            else{
                if(temprow != rowsum) return  false;
            }
        }
        int colsum =-1;
        for(int i = startc ; i < endc ; i++){
            int tempcol =0;
            for(int j = startr ; j < endr ; j++){
                if(grid[j][i] > 9 or grid[j][i] == 0) return false;
                tempcol +=grid[j][i];
            }
            if(colsum==-1) colsum = tempcol;
            else{
                if(tempcol != colsum) return  false;
            }
        }
        int diagsum = 0;
        int indr = startr;
        int indc = startc;
        for(int i = 0 ; i < 3 ; i++){
            if(grid[indr+i][indc+i] >9 or grid[indr+i][indc+i] ==0 )return false;
            diagsum+=grid[indr+i][indc+i];
        }
        return (rowsum ==colsum and colsum == diagsum and (s.size()==9));
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int res =0;
        if(grid.size() <3 or grid[0].size()<3) return 0;
        for(int i = 0 ; i <= grid.size()-3;i++){
            for(int j = 0 ; j <= grid[0].size()-3; j++){
                if(check(i  , j , i+3 , j+3 , grid)) {
                    res++;
                }
            }
        }
        return res;
    }
};