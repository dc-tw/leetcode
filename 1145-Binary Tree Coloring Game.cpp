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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        pair<int , int > res;
        dfs(root, x, res);
        return (n/2) < max(max(res.first, res.second), n - res.first - res.second - 1);
    };
    int dfs(TreeNode* node, int x, pair<int , int >& res){
        if(!node)return 0;
        int l = dfs(node->left, x, res), r = dfs(node->right, x, res);
        if(node->val == x){
            res.first = l;
            res.second = r;
        }
        return l+r+1;
    };
};