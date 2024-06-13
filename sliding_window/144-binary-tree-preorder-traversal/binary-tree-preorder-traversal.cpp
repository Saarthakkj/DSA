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
    
    vector<int> preorderTraversal(TreeNode* root) {
       vector<int> v; 
       stack<TreeNode*> s; 
       if(root == NULL){
            return {};
       }

       s.push(root) ;
       while(!s.empty()){
            int size = s.size() ;
            for(int i = 0 ; i< size ; i++){
                TreeNode* node = s.top();
                s.pop();
                v.push_back(node->val);
                if(node->right){
                    s.push(node->right);
                }
                if(node->left){ 
                    s.push(node->left) ;
                }
            }
       }


       return v;
    }
};