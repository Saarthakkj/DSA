class Solution {
public:
    int swimInWater(vector<vector<int>>& graph) {
        priority_queue< pair< int , pair<int , int>>  , vector<pair<int, pair<int, int>>> ,greater<pair<int , pair<int , int>>> > pq; 

        int n = graph.size() ; 
        int d_row[4] = {-1 , 0 , 1 , 0};
        int d_col[4] = {0 , -1  , 0 , 1}; 

        pq.push({graph[0][0] , {0 , 0}}) ;
        vector<vector<int>> vis(graph.size() , vector<int>(graph.size() , 0)) ;

        vis[0][0] =1; 

        while(!pq.empty()){
            int row = pq.top().second.first ; 
            int col = pq.top().second.second ; 
            int time = pq.top().first; 

            pq.pop() ;
            cout<< "row : "<< row<< " col : "<< col << endl;

            if(row == n-1 and col == n-1 ){
                return time; 
            }

            for(int i = 0 ; i < 4 ; i++){
                int n_row = d_row[i] + row; 
                int n_col = d_col[i] + col ; 
                if(n_row >= 0 and n_row < n and n_col >=0 and n_col < n and vis[n_row][n_col] == 0){
                    pq.push({max(time , graph[n_row][n_col]) , {n_row ,n_col}} ) ; 
                    vis[n_row][n_col] ++ ;
                }
            }
        }

        return -1; 
    }
};