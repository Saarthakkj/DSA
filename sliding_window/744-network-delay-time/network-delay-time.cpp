class Solution {
public:
    int dijkstra(int source , int V , vector<vector<int>>& graph ){

        priority_queue< pair< int, int>  , vector< pair<int , int>> , greater< pair<int, int> > > pq; 
        vector<int> times(V+1 , INT_MAX) ; 
        times[source] = 0 ;
        pq.push({0 , source}) ;
        int count_v = 0 ; 
        int max_time = 0 ;

        while(!pq.empty()){
            int v = pq.top().second ; 
            int time = pq.top().first ;
            pq.pop() ; 
            
            max_time = max(time, max_time) ; 

            if(time > times[v]){
                continue;
            }

            count_v ++ ; 
            
            for(auto& it : graph){
                //cout<< " it[1]  : "<< it[1];
                if(it[0] == v and times[it[1]] > time+it[2]){
                    pq.push({time + it[2] , it[1]}) ; 
                    //cout<< "time: "<< time + it[2] << " v: "<< it[1] << endl;
                    times[it[1]] =  time+it[2] ;
                }
            }

            if(count_v == V){
                return max_time;
            }
        };

        return -1; 


    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        return dijkstra(k , n , times) ;
    }
};