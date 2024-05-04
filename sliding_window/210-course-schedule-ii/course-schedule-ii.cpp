class Solution {
public:
    stack<int> s; 
    bool dfs(int v ,  vector<vector<int>>& graph , vector<int>& visited , int V  , vector<int>& path_vis){
        visited[v] = 1;
        path_vis[v] = 1; 
        for(int i = 0 ; i < graph[v].size() ; i++ ){
            if(visited[graph[v][i]]  == 0){
                //visited[graph[v][i]] = 1;
                if(dfs(graph[v][i] , graph , visited , V , path_vis)){
                    return true;
                } ;
                //s.push(graph[v][i]) ;
            }
            else if(path_vis[graph[v][i]]  == 1){
                return true;
            }
        }
        path_vis[v] = 0 ;
        s.push(v) ;

        return false;

    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // int m = prerequisites.size() ; 
        // int n = prerequisites[0].size(); 
        vector<vector<int>> graph(numCourses); 
        for(int i = 0 ; i < prerequisites.size() ; i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]) ; 
        }
        //cout<< "reached here" ;
        //made the adjacency list of this graph

        vector<int> visited(numCourses , 0);
        vector<int> path_vis(numCourses , 0) ; 

        for(int i = 0 ; i < numCourses ; i++ ){
            if(!visited[i]){
                if(dfs(i , graph , visited , numCourses , path_vis)){
                    return {}; 
                }; 
            }   
        }

        //not cycle
        vector<int> ans ; 
        while(!s.empty()){
            ans.push_back(s.top()) ;
            s.pop() ;
        }

        return ans;
    }
};