class Solution {
public:
    void dfs(map<int, int>& visited  , vector<vector<int>>& arr , int u ){
        visited[u]++;
        for(int i = 0 ; i < arr.size() ; i++){
            if(arr[u][i] == 1 and visited[i] == 0){
                visited[i] ++ ; 
                dfs(visited , arr , i) ; 
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        map< int, int> visited; 
        int province = 0  ; 
        for(int i = 0 ; i < isConnected.size() ; i++){
            if(!visited[i]){
                dfs(visited , isConnected , i)  ;
                province ++ ;
                //visited[i]++ ;
            }
        }
        return province;
    }
};