class DisjointSet{
public: 
    vector<int> parent;  
    vector<int> rank ;
    vector<int>size; 

    DisjointSet(int n){
        size.resize(n+1); 
        parent.resize(n+1);
        rank.resize(n+1) ;
        for(int i = 0; i <= n ; i++){
            parent[i]=i ;
            size[i] = 1 ; 
        }
        for(int  i = 0 ; i <= n ;i++){
            rank[i] = 0 ;
        }
    }

    int findUpar(int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = findUpar(parent[node]) ;
    }

    void UnionRank(int u , int v){
        int Up_u = findUpar(u) ;
        int Up_v = findUpar(v);

        if(Up_u == Up_v){
            return ; 
        }

        if(rank[Up_u] >  rank[Up_v]){
            parent[Up_v] = Up_u ;
        }
        else if(rank[Up_u] < rank[Up_v]){
            parent[Up_u] = Up_v ; 
        }
        else if(rank[Up_u] == rank[Up_v]){
            parent[Up_u] = Up_v ;
            rank[Up_v] ++;
        }
    }

    void UnionSize(int u , int v){
        int up_u =  findUpar(u) ;
        int up_v = findUpar(v) ;

        if(up_u == up_v){
            return ;
        }
        if(size[up_u] > size[up_v]){
            parent[up_v] =  up_u ;
            size[up_u]+= size[up_v] ;
        }
        else{
            parent[up_u] = up_v ;
            size[up_v]+= size[up_u] ;
        }
    }
};


class Solution {
public: 
    int d_row[4] = {-1 , 0 , 1 ,0 };
    int d_col[4] = {0 , 1 ,0 ,-1};

    int largestIsland(vector<vector<int>>& graph) {
        int n =graph.size() ;

        DisjointSet ds(n*n+1) ; 
        int maxisland_size = -1;


        //vector<vector<int>> vis(n , vector<int>(n , 0));
        //union by disjoint set

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(graph[i][j] == 1 ) {//and vis[i][j] == 0 ){
                    //cout<< " i : "<< i << " j : "<< j ;
                   /// vis[i][j] ++;
                    for(int k = 0; k < 4; k++){
                        int n_row = d_row[k] + i;
                        int n_col = d_col[k] + j ; 

                        if(n_row < n and n_row >= 0 and n_col < n and n_col >= 0 and graph[n_row][n_col] == 1){
                            //cout<< "i : "<< n_row << " j : "<< n_col << endl;
                            ds.UnionSize(n*i+j , n*n_row + n_col);
                            //vis[n_row][n_col]++ ;
                        }
                    }

                    //cout<< "union size : "<< ds.size[n*i + j]  << "upar : " << ds.findUpar(n*i+j) << "ds size 0 : "<< ds.size[0] << endl;
                }
            }
        }
        
        for(int i = 0 ; i < n ; i++){
            for(int j =0 ; j < n; j++){
                if(graph[i][j] == 0) {
                    int island_size = 0 ;
                    set<int> s; 
                    for(int k = 0 ; k< 4; k ++){
                        int n_row = d_row[k] + i;
                        int n_col = d_col[k] + j ; 

                        if(n_row < n and n_row >= 0 and n_col < n and n_col >= 0 and graph[n_row][n_col]== 1){
                            // island_size+=  ds.size[ds.findUpar(n*n_row + n_col)] ; 
                            //cout<< " n*n_row + n_col: "<< n*n_row + n_col ;
                            //cout<< "upar: "<< ds.findUpar(n_row*n + n_col) ;
                            s.insert(ds.findUpar(n_row*n + n_col)) ;

                        }
                    }

                    for(auto it : s){
                        //cout<< "it " << it<< " ds.size : "<< ds.size[it] ;
                        island_size+= ds.size[it] ;
                        //cout<< " it : "<< it;
                    }

                    //cout<< endl;
                    island_size++ ; 

                    maxisland_size = max(island_size , maxisland_size) ;
                }
            }
        }

        for(int cellno =0 ; cellno < n*n ; cellno++){
            maxisland_size  = max(maxisland_size , ds.size[ds.findUpar(cellno)]); 
        }

        return maxisland_size ; 
    }
};