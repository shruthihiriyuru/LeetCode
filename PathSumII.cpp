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
    
    void findPaths(TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& res) {
        if (!root)
            return;
        
        path.push_back(root->val);
        
        if (!root->left && !root->right && root->val == sum)
            res.push_back(path);
        
        findPaths(root->left, sum-root->val, path, res);
        findPaths(root->right, sum-root->val, path, res);
        
        path.pop_back();
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        
        findPaths(root, sum, path, res);
        
        return res;
    }
};
