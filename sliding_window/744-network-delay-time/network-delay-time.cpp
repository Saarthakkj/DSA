class Solution {
public:
    int dijkstra(int source , int V , vector<vector<int>>& graph ){

        priority_queue< pair< int, int>  , vector< pair<int , int>> , greater<pair<int, int>>  > pq; 
        //vector<int> times(V+1 , INT_MAX) ; 


        //times[source] = 0 ;

        vector<int> visited(V+1 , 0) ; 
        //visited[source]++; 

        pq.push({0 , source}) ;
        //int count_v = 0 ; 
        int max_time = 0 ;

        while(!pq.empty()){
            int v = pq.top().second ; 
            int time = pq.top().first ;
            pq.pop() ; 
            if(visited[v]){
                continue;
            }
            max_time = max(time, max_time) ; 
            visited[v]++;
            //count_v ++ ; 
            
            for(auto& it : graph){
                //cout<< " it[1]  : "<< it[1];
                if(it[0] == v and visited[it[1]] == 0){
                    cout<< "v :"<< v << "it[1] : "<< it[1] << " time + it[2]: "<< (time + it[2]) << endl;
                    pq.push({time + it[2] , it[1]}) ; 
                    //cout<< "time: "<< time + it[2] << " v: "<< it[1] << endl;
                    //times[it[1]] =  time+it[2] ;
                    //visited[it[1]]++;
                }
            }

            // if(count_v == V){
            //     return max_time;
            // }
        };

        for(int i = 1 ; i <= V ; i++){
            if(visited[i] == 0){
                return -1; 
            }
        }

        return max_time; 


    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        return dijkstra(k , n , times) ;
    }
};