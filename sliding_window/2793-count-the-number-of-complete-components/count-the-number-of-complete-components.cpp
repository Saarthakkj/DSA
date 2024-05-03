class Solution {
public:
    int countCompleteComponents(int V, vector<vector<int>>& edges) {
        // Create an adjacency list representation of the graph
        int count = 0 ;
        vector<vector<int>> graph(V);
        for (const vector<int>& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]); 
        }
        vector<bool> visited(V, false);
        for (int node = 0; node < V; ++node) {
            vector<int> components ; 
            if (!visited[node]) {
                dfs(node, graph, visited , components);
                if(isComplete(components , graph)){
                    //cout<< "hey "<<endl;
                    count++ ;
                }
            }
        }
        return count;
    }
private:
    // DFS exploration
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited , vector<int>&  components) {
        components.push_back(node) ; 
        //cout<< "node : "<< node << endl ;
        visited[node] = true;
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, graph, visited , components );
            }
        }
    }

    bool isComplete(vector<int>& components , vector<vector<int>>& graph){
        int k = components.size()  ; 
        //cout<< " k is : "<< k << endl;
        for(int comp : components){
            //cout<< " comp: "<< comp << " graph[comp] : "<< graph[comp].size()<< endl;
            if(graph[comp].size() != k-1){
                return false;
            }
        }
        return true;
    }
};

