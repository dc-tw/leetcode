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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root) dfs(root, "", res);
        return res;
    }
    void dfs(TreeNode* node, string out, vector<string>& res) {
        if (!node->left && !node->right) res.push_back(out + to_string(node->val));
        if (node->left) dfs(node->left, out + to_string(node->val) + "->", res);
        if (node->right) dfs(node->right, out + to_string(node->val) + "->", res);
    }
};