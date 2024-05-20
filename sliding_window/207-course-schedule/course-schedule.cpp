class Solution {
public:
    bool dfs(int v , vector<vector<int>>& graph , vector<int>& visited , vector<int>& path_visited){

        visited[v] = 1 ; 
        path_visited[v] = 1;


        for(int i = 0 ; i < graph[v].size() ; i++){
            if(visited[graph[v][i]] == 0){
                if(dfs(graph[v][i] , graph , visited , path_visited)){
                    return true;
                } ;
            }
            if(path_visited[graph[v][i]] == 1){
                return true;
            }
        }

        path_visited[v] = 0 ;

        

        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses) ; 

        for(int i = 0 ; i < prerequisites.size() ; i++ ){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]) ; 
        }

        vector<int> visited(numCourses) ;
        //made graph for the pre requisites

        for(int i  = 0 ; i < graph.size() ; i++){
            if(visited[i] == 0){
                vector<int> path_visited(numCourses); 
                if(dfs(i , graph , visited , path_visited )){
                    return false;
                }
            }
        }

        return true;
    }
};