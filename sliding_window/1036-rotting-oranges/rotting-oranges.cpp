class Solution {
    struct orange{
        int i ;
        int j;
        int time;

        orange(int i_val, int j_val, int time_val) : i(i_val), j(j_val), time(time_val) {}
    };
public:

    int orangesRotting(vector<vector<int>>& graph) {
        queue<orange> q;
        
        int max_row = graph.size();
        int max_col = graph[0].size();

        int rotten =0  ;
        int visited[max_row][max_col]  ;

        for(int i =0 ; i < graph.size() ; i++){
            for(int j = 0;  j < graph[0].size() ; j++){
                if(graph[i][j] == 2){
                    rotten++;
                    q.push(*new orange(i , j , 0)) ;
                    visited[i][j] =1 ;
                }
                else{
                    visited[i][j] = 0 ;
                }
            }
        }

        

        int max_time =0  ;

        vector<int> d_row = {0 , 1 , 0 , -1};
        vector<int> d_col = {1 , 0 , -1 , 0}; 
        //vector<int> visited(max_row*max_col , flase);

        while (!q.empty()){
            orange cell = q.front();
            //visited[cell]
            q.pop();
           

            int row = cell.i;
            int col = cell.j;
            max_time = cell.time;
            
            graph[row][col] = 2; // orange rotten
            visited[row][col]  = 1;

            for (int i = 0; i < 4; i++) {
                //cout<< " row : "<< row << " col : "<< col << " i is: "<< i ; 
                if (row + d_row[i] < max_row && col + d_col[i] < max_col and row+d_row[i] >=0 and col+d_col[i] >=0  && graph[row + d_row[i]][col + d_col[i]] == 1 and visited[row+d_row[i]][col+d_col[i]] == 0) { 
                    graph[row + d_row[i]][col + d_col[i]] = 2;
                    //cout<< " row+d-row : "<< row+d_row[i] << " col+ d_col : "<< col+d_col[i] << " time :"<< max_time+1<< endl; 
                    q.push(*new orange(row + d_row[i], col + d_col[i] , max_time+1));
                }

            }
        }

        for(int i =0 ; i < max_row ; i++){
            for(int j =0 ; j < max_col ; j++){
                if(graph[i][j] == 1){
                    return -1; 
                }
            }
        }
        

        return max_time;  
    }
};