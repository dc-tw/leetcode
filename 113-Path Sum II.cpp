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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if(!root) return res;
        vector<int> temp;
        dfs(root, res, temp, sum);
        return res;
    }

    void dfs(TreeNode* root,vector<vector<int>> &res, vector<int> temp, int sum)
    {
        temp.push_back(root->val);
        if(!root->left && !root->right && sum == root->val) res.push_back(temp); 
        if(root->left) dfs(root->left, res, temp, sum - root->val);
        if(root->right) dfs(root->right, res, temp, sum - root->val);
    }
};