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
    int sumNumbers(TreeNode* root) {
        if(!root)return 0;
        int ans = 0;
        dfs(root, &ans, 0);
        return ans;
    }
    void dfs(TreeNode* root, int* sum, int path){
        if(!root->left&&!root->right)*sum += (path*10 + root->val);
        if(root->left)dfs(root->left, sum, path*10 + root->val);
        if(root->right)dfs(root->right, sum, path*10 + root->val);
    }
};