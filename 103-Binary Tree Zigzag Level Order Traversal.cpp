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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        vector<TreeNode*> curr,next;
        curr.push_back(root);
        while(!curr.empty()) {
            ans.push_back({});
            for(TreeNode* node : curr) {
                ans.back().push_back(node->val);
                if(node->left) next.push_back(node->left);
                if(node->right) next.push_back(node->right);
            }
            if(ans.size()%2 == 0)reverse(ans.back().begin(), ans.back().end());
            curr.swap(next);
            next.clear();
        }
        return ans;
    }
};