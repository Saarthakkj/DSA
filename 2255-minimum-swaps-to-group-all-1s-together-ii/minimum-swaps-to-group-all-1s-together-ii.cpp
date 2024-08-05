class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n =  nums.size();
        int k =0;
        for(int a : nums)k+=a;
        if(k == 0 or k == n-1)return 0;
        //window of "k"  with most ones
        //maintaing a vector
        // v[1]  = "ones" between 1..k
        //v[0] = "ones" betweeen 0..k-1
        //O(n*k) complexity 
        int maxv = -1;
        vector<int> v(n);
        for(int i = 0 ; i < n ; i++) nums.push_back(nums[i]);
        //do it for the first "k"
        for(int i =0 ; i < k ; i++) v[0] += nums[i];
        maxv = v[0];
        //now for v[1]... v[n-1]

        for(int i = 1 ;i < n ; i++){
            v[i] = v[i-1]+ nums[k-1+i]-nums[i-1];
            maxv = max(maxv , v[i]);
        }
        return (k-maxv);

    }
};