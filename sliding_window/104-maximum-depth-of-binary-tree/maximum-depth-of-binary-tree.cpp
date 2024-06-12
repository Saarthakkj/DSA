/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        //int temp_count = 0;
        int count = 0;

        stack<pair<int , TreeNode*>> s;
        if(!root){
            return 0 ;
        }
        s.push({1 , root});

        while(!s.empty()){
            int temp = s.top().first;
            count = max(temp , count);
            TreeNode* node = s.top().second; 
            s.pop() ;

            if(node->left){
                s.push({temp+1 , node->left});
            }
            if(node->right){
                s.push({temp+1 , node->right}); 
            }
        }

        return count;
    }
};