class Solution {
public:
    double dijkstra(vector<vector<pair<int , double>>>& graph , int start , int end ,  int n){
        vector<double> maxProb(n , 0.0);
        priority_queue< pair<double , int> , vector<pair<double , int>> > mH;
        mH.push({1.0, start});
        while(!mH.empty()){
            auto [p , u] = mH.top();
            //cout<< " p: "<< p << " u : "<< u << endl;
            mH.pop();
            for(auto& [node , p1] : graph[u]){
                //cout<< "u : "<< u << " node: "<< node << " p1 : " << p1 << endl;
                if(p1*p > maxProb[node]){
                    maxProb[node] = p1*p ;
                    //cout<< "p1 : "<< p1 << endl;
                    mH.push({maxProb[node]  , node});
                    //cout<< " maxprob : "<< maxProb[node] << " node : "<< node << endl;
                };
            };
        }
        return maxProb[end];
    }
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int , double>>> adj(n , vector<pair<int , double>>());
        int i = 0;
        for(auto temp: edges){
            adj[temp[0]].push_back({temp[1] , succProb[i]});
            adj[temp[1]].push_back({temp[0] , succProb[i]});
            //cout<< "succProb : "<< succProb[i] << " ";
            i++;
            //cout<< " temp : "<< temp[0] << " " <<  temp[1]<< endl;
        }
        //adj.erase(remove(adj.begin() , adj.end() , vector<pair<int , double>>()) , adj.end());

        return dijkstra(adj , start_node , end_node , n) ; 
    }
};