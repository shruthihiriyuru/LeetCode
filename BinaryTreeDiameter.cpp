/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root, int& ans) {
        if (root == NULL)
            return 0;
        int lheight = height(root->left, ans);
        int rheight = height(root->right, ans);
        ans = max(ans, lheight+rheight);
        
        return 1 + max(lheight, rheight);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        
        int h = height(root, ans);
        
        return ans;
    }
};
