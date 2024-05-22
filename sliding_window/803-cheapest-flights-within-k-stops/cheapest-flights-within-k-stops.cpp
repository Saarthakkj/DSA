class Solution {
public:
    int dijkstra(int src , int dest , int V   , vector<vector<int>>& graph ,int k ){

         vector<pair<int, int>> adj[V]; 
        for(int i = 0 ; i < graph.size() ; i++){
            adj[graph[i][0]].push_back({graph[i][1] ,graph[i][2]});
        }

        priority_queue<pair<int, pair< int, int>>  , vector< pair<int , pair<int , int>> > , greater< pair<int , pair<int, int>>>  > pq; 
        vector<int> costs(V , INT_MAX) ; 
        pq.push({0 , {0 , src}}) ;
        //cout<< "hery";
        costs[src]  = 0;

        int min_cost = INT_MAX ; 
        

        while(!pq.empty()){
            int stop = pq.top().first ; 
            int cost = pq.top().second.first ;
            int curr = pq.top().second.second ; 

            pq.pop() ; 

            if(stop > k){
                continue;  
            }
            //cout<< "stop : "<< stop << "cost: "<< cost << "curr : "<< curr << endl;
            if(curr == dest){
                //cout<< "k : "<< k << " stops :"<< stop ;
                if(stop-1 <=k){
                    min_cost = min(cost, min_cost); 
                }  
            }       
            
            for (const auto& it : adj[curr]) {
                int node = it.first ; 
                int node_cost = it.second;
                
                if (costs[node] > (cost + node_cost) and stop<= k) {
                    costs[node]= cost + node_cost;
                    pq.push({stop + 1, {costs[node],it.first}});
                }
            }
            

        };

        if(costs[dest] == INT_MAX){
            return -1;
        }

        return costs[dest]; 

    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        return dijkstra(src , dst , n, flights ,  k ) ;
    }
};