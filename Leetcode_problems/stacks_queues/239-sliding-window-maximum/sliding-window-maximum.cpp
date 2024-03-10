class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        deque<int> dq;
        vector<int> ans ; 
        for(int i = 0  ; i < arr.size(); i++){
            int curr = arr[i];
            //first handle out of the bound array 
            if(!dq.empty() and dq.front() == i-k){
                dq.pop_front();
            }
            
            //then handle if the curr element is greater than element
            //pop from behind
            while(!dq.empty() and arr[dq.back()] < curr){
                dq.pop_back();
            }
            //now dequeue is ready to insert the current element
            dq.push_back(i);
            if(i>= k-1){
                //time to insert the elements in the ans array 
                ans.push_back(arr[dq.front()]);
            }
        }
        return ans;
    }
};