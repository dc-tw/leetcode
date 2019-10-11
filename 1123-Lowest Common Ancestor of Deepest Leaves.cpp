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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return solve(root).first;
     }
pair<TreeNode*, int> solve(TreeNode *rt) {
        if (rt == nullptr)
            return make_pair(nullptr, 0);

        auto l = solve(rt -> left);
        auto r = solve(rt -> right);

        if (l.second == r.second) {
            return make_pair(rt, l.second + 1);
        } else if(l.second > r.second) {
            return make_pair(l.first, l.second + 1);
        } else {
            return make_pair(r.first, r.second + 1);
        }
    }
};