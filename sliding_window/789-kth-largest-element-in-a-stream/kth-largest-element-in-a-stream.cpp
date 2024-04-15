class KthLargest {
public:
    priority_queue<int , vector<int> , greater<int>> min_heap  ; 
    int kay ; 
    KthLargest(int k, vector<int>& nums) {
        kay = k ; 
        for(int i = 0 ;i < nums.size() ; i++){
            min_heap.push(nums[i]) ; 
            if(min_heap.size() > kay){
                min_heap.pop() ; 
            }
        }

        
        return  ; 
    }
    
    int add(int val) {
        min_heap.push(val); 
        if(min_heap.size() > kay){
            min_heap.pop() ; 
        }
        return min_heap.top()  ;
        //minheap top is the lowest element among all the elements i.e. kth largest elemnt
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */