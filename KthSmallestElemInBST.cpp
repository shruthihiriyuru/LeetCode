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
    
    int inorder(TreeNode* root, int& k) {
        if (root) {
            int res = inorder(root->left, k);
            
            return !k?res:!--k?root->val:inorder(root->right, k);
        }
        return 0;
    }

    int kthSmallest(TreeNode* root, int k) {
        return inorder(root, k);
    }
};
