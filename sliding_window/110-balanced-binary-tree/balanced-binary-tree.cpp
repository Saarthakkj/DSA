class Solution {
public:
    int checkHeight(TreeNode* node) {
        if (node == nullptr) return 0;

        int lh = checkHeight(node->left);
        if (lh == -1) return -1; // Left subtree is not balanced

        int rh = checkHeight(node->right);
        if (rh == -1) return -1; // Right subtree is not balanced

        if (abs(lh - rh) > 1) return -1; // Current node is not balanced

        return max(lh, rh) + 1; // Return the height of the subtree rooted at this node
    }

    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};
