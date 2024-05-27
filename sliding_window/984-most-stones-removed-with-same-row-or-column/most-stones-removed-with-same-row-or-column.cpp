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
            parent[up_v] =  u ;
            size[up_u]+= size[up_v] ;
        }
        else{
            parent[up_v] = up_u ;
            size[up_v]+= size[up_u] ;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        
        int max_row = 0 ;
        int max_col = 0 ; 
        for(int i = 0 ; i < stones.size() ; i++){
            max_row = max(stones[i][0] , max_row) ; 
            max_col = max(stones[i][1] , max_col) ;
        }

        DisjointSet ds(max_row+ max_col +1) ;

       // cout<< "max row: "<< max_row << "max_col : "<< max_col << endl;

        // max_row; 
        // max_col; 

        map<int , int> uniqueStones ; 

        for(auto it : stones){
           
            int row = it[0] ; 
            int col = it[1] + max_row+1 ;

            //cout<< "row : "<< row << " col : "<< col << endl;
            ds.UnionSize(row , col) ;
            uniqueStones[row] = 1; 
            uniqueStones[col] = 1;

        }

        int scc= 0 ; 

        for(auto itr : uniqueStones){
            //cout<< " itr  :"<< itr.first << " parent: "<< ds.findUpar(itr.first) << endl;
            if(ds.findUpar(itr.first) == itr.first ){
                scc ++ ; 
                //if node itself is the ultimate parent of it, then 
                //we found a self pointing node
                //summation of all these nodes will be no. of sccs
            }
        }

        //cout<< " scc : "<< scc << endl;

        return stones.size() - scc ;
    }
};