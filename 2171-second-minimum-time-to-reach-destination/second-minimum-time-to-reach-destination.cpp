class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> list(n+1);
        for(int i = 0 ; i  < edges.size() ; i++){
            list[edges[i][0]].push_back(edges[i][1]);
            list[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> dist1(n+1 , INT_MAX);
        vector<int> dist2(n+1 , INT_MAX);
        dist1[1] =0;
        priority_queue<pair<int ,int> , vector<pair<int, int>>, greater<pair<int, int>>> minH; 
        minH.push({0 , 1});
        //vector<int> freq(n+1);
        while(!minH.empty()){
            auto [timeTaken , node] = minH.top();
            minH.pop();
            //freq[node]++;
            if(dist2[node] != INT_MAX and node == n ) return dist2[node];
            int newTimetaken =0;
            //calculate for stalling
            if(((timeTaken)/change )%2){
                //just crossed the green to red light phase
                newTimetaken = (timeTaken/change+1)*change + time;
            }
            else newTimetaken = timeTaken +time;

            for(auto neighbour : list[node]){
                if(dist1[neighbour] > newTimetaken ){
                    dist2[neighbour]= dist1[neighbour];
                    dist1[neighbour] = newTimetaken ;
                    minH.push({newTimetaken , neighbour});
                }
                else if(dist2[neighbour] > newTimetaken and newTimetaken != dist1[neighbour]){
                    dist2[neighbour] = newTimetaken;
                    minH.push({newTimetaken , neighbour});
                }
            }
        }

        return -1;

    }
};