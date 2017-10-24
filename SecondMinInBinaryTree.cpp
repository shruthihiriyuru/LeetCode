/*
Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree 
has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among 
its two sub-nodes. Given such a binary tree, you need to output the second minimum value in the set made of all the 
nodes' value in the whole tree. If no such second minimum value exists, output -1 instead.
*/
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
    
    int findSecondMin(TreeNode* root, int first) {
        if (root == NULL)
            return -1;
        
        if (root->val != first)
            return root->val;
        
        int l = findSecondMin(root->left, first);
        int r = findSecondMin(root->right, first);
        
        if (l == -1)
            return r;
        if (r == -1)
            return l;
        
        return min(l, r);
            
    }
    
    int findSecondMinimumValue(TreeNode* root) {

        return findSecondMin(root, root->val);
    }
};
