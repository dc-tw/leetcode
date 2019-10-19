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
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
    }
    int dfs(TreeNode* root, int mx, int mn){
        if(!root)return mx - mn;
        mx = max(root->val, mx);
        mn = min(root->val, mn);
        return max(dfs(root->left, mx, mn), dfs(root->right, mx, mn));
    }
};