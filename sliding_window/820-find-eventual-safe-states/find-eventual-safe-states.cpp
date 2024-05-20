class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        queue<int> q ;
        vector<int> inDegree(graph.size() , 0) ; 
        vector<int> adj[graph.size()]  ; 

        for(int i = 0 ; i < graph.size() ; i++){
            for(auto it : graph[i]){
                adj[it].push_back(i) ; 
                inDegree[i]++ ; 
            }
        }


        for(int i = 0 ; i < graph.size() ; i++){
            if(inDegree[i] == 0){
                q.push(i) ; 
            }
        }

        vector<int> safenode ; 

        //for 0 - indegrees

        while(!q.empty()){

           // cout<< "true" ;
            int node = q.front()  ;
            q.pop() ; 
            safenode.push_back(node); 

            for(auto& it : adj[node]){
                inDegree[it]-- ; 
                if(inDegree[it] == 0){
                    cout<< "it : "<< it<< endl;
                    q.push(it) ;
                } 
            }

        }

        sort(safenode.begin() , safenode.end());

        return safenode; 

    }
};