class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans ;
        int i = 0 ;
        while(i<nums.size()){
            int key =  nums[i];

            bool found1 = false;
            //cout<< "key is :"<< key << endl;
            for(int j = i ; j< nums.size() ; j++){
                if(nums[j] > key){
                    //cout<< "1. appending  : "<< nums[j] << endl;
                    ans.push_back(nums[j]);
                    found1 = true;
                    break;
                }
            }
            if(found1){
                i++;
                continue;
            }

            //if not found in the first try: 
            bool found2 = false;
            for(int j = 0 ; j< i ; j++){
                if(nums[j] > key){
                    //cout<< "2. appending  : "<< nums[j] << endl;
                    ans.push_back(nums[j]);
                    found2 = true;
                    break;
                }
            }
            if(found2){
                i++;
                continue;
            }

            //if not found in the second try also: 
            ans.push_back(-1);
            i++;
        }
        return ans;
    }
};