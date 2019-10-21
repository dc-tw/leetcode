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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        dfs(root, true, res, to_delete);
        return res;
    }
    void dfs(TreeNode*& node, bool isRoot, vector<TreeNode*>& res, vector<int>& to_delete) {
        if (!node) return;
        bool isDel = delCurNode(node, to_delete);
        dfs(node->left, isDel, res, to_delete);
        dfs(node->right, isDel, res, to_delete);
        if (isRoot && !isDel) {
            res.push_back(node);
        }
        if (!isRoot && isDel) {
            node = NULL;
        }
    }
    bool delCurNode(TreeNode* root, vector<int>& to_delete) {
        for (int val : to_delete) {
            if (root->val == val) {
                return true;
            }
        }
        return false;
    }
};