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
    string smallestFromLeaf(TreeNode* root) {
        vector<string> res;
        dfs(root, "", res);
        sort(res.begin(), res.end());
        return res[0];
    }
    void dfs(TreeNode* root, string path, vector<string>& res) {
        if (!root->left && !root->right) {
            res.push_back(char('a' + root->val) + path);
            return;
        }
        if (root->left)
            dfs(root->left, char('a' + root->val) + path, res);
        if (root->right)
            dfs(root->right, char('a' + root->val) + path, res);
    }
};