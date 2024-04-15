class KthLargest {
public:
    priority_queue<int , vector<int> , greater<int>> max_heap  ; 
    int kay ; 
    KthLargest(int k, vector<int>& nums) {
        kay = k ; 
        for(int i = 0 ;i < nums.size() ; i++){
            max_heap.push(nums[i]) ; 
            if(max_heap.size() > kay){
                max_heap.pop() ; 
            }
        }

        
        return  ; 
    }
    
    int add(int val) {
        max_heap.push(val); 
        if(max_heap.size() > kay){
            max_heap.pop() ; 
        }
        return max_heap.top()  ;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */