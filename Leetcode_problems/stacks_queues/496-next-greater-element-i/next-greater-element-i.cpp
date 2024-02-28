class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans ;
        int i =0 ;
        while(i<nums1.size()){
            auto temp = find(nums2.begin() , nums2.end() , nums1[i]);
            //iterator of nums[i] in nums2;
            bool found = false;
            for(auto it = temp ; it != nums2.end() ; it++){
                if((*it) > (*temp)){
                    found = true;
                    ans.push_back((*it));
                    break;
                }
            }
            if(!found){
                ans.push_back(-1);
            }
            i++;
        }
        return ans;
    }
};