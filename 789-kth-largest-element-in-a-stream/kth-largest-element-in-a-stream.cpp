class KthLargest {
public:
    priority_queue<int, vector<int> , greater<int>> mH;
    int sz = 0;
    KthLargest(int k, vector<int>& nums) {
        int size = nums.size();
        //maintain the size "k"
        for(int ele : nums){
            mH.push(ele);
            if(mH.size() > k) mH.pop();
        }
        sz = k;

    }
    int add(int val) {
        if(mH.size()==0 or mH.size() < sz) {
            mH.push(val);
        }
        else if(val > mH.top()){
            cout<< " val : "<< val << endl;
            mH.push(val);
            mH.pop();
        }
        return mH.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */