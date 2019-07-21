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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res;
        inOrder(root, res);
        return res[k - 1];
    }
    void inOrder(TreeNode* root, vector<int>& res) {
        if (!root) return;
        inOrder(root->left, res);
        res.push_back(root->val);
        inOrder(root->right, res);
    }
};