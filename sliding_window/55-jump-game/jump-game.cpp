class Solution {
public:
   bool canJump(vector<int>& nums) {
        int lastPos = nums.size() - 1; // Index of the last element

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i + nums[i] >= lastPos) {
                lastPos = i; // Update the last position that can reach the end
            }
        }

        return lastPos == 0; // Check if we can reach the start from the last position
    }
    // 
    
};