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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
       // sort(accounts.begin() , accounts.end()) ;
        int n = accounts.size() ; 

        DisjointSet ds(n) ;

        unordered_map<string, int> mpp ;

        for(int i =0; i < accounts.size() ; i++){
            for(int j = 1 ; j < accounts[i].size() ; j++){
                string mails = accounts[i][j] ;
                if(mpp.find(mails) == mpp.end()){
                    mpp[mails] = i ; 
                    //cout<< "mpp[mails] : " << mails <<  " i : "<< i << endl;
                }
                else{
                    ds.UnionSize(mpp[mails] , i) ; 
                    //cout<< "mpp[mails] : " << mpp[mails] << " i : "<< i << endl;
                }
            }
        }

        vector<string> merged_mails[n]; 

        for(auto it : mpp){
            merged_mails[ds.findUpar(it.second)].push_back(it.first) ;
            //cout<< " parent  : "<<  ds.findUpar(it.second) << " mail : "<< it.first<< endl;
        }

        vector<vector<string>> res ;

        for(int i = 0 ; i < n ; i++){
            if(merged_mails[i].size() != 0 ){
                vector<string> temp = {accounts[i][0]} ; 
                sort(merged_mails[i].begin() , merged_mails[i].end()) ;
                for(auto itr : merged_mails[i]){
                    temp.push_back(itr);
                }
                res.push_back(temp) ;
            }
        }

        return res;
        

    }
};