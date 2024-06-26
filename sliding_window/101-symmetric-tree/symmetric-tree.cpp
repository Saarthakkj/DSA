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
    bool check(TreeNode* root1 , TreeNode* root2){
        if(root1 == NULL and root2 == NULL){
            return true;
        }
        else if(root1 == NULL or root2 == NULL){
            return false;
        }

        if(root1->val == root2->val and check(root1->left, root2->right) and check(root1->right , root2->left)){
            return true;
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return check(root->left , root->right) ;
    }
};