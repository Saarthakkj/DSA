class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> max_heap ; 
        queue<pair< int ,int> > q ; 

        map<char , int> mpp ;
        for(int i = 0 ; i < tasks.size() ; i++){
            mpp[tasks[i]] ++ ; 
        }

        for(auto it = mpp.begin() ; it != mpp.end() ; it++){
            max_heap.push(it->second)  ; 
            //cout<< "max_heap : "<< max_heap.top()  ;
        }

        //made the max heap of all the frequency of the characters

        int time =  0; 
        //cout<< "max_heap: " << max_heap.empty() << "queue empty" << q.empty() ;
        while(!(q.empty() and max_heap.empty())){
            time++ ; 

            //cout<< " time is : "<< time << endl ; 

            //search for any element in queue if ready to be pop out in this given time
            //only front element will be there to pop out
            if(q.front().second == time){
                //matches the time 
                max_heap.push(q.front().first )  ;
                q.pop()  ;
            }


            //make an operation
            if(max_heap.empty()){
                continue ;
            }
            int freq =  max_heap.top() ; 
            if(freq-1 == 0){
                max_heap.pop()  ;
                continue  ; 
            }
            pair<int , int> temp = {freq-1  , time+1+ n}; 
            max_heap.pop()  ;
            q.push(temp )  ; 
             
        }

        return time ; 
    }
};