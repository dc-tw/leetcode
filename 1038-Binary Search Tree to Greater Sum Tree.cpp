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
    TreeNode* bstToGst(TreeNode* root) {
        if(root)  {
            dfs(root, 0);
        }
        return root;
    }
    
    int dfs(TreeNode* node, int diff) {
        if(node->right) {
            int rdiff = dfs(node->right, diff);    
            node->val += rdiff;
        }else {
            node->val += diff;
        }
        
        if(!node->left) {
            return node->val;
        }else {
            int left = dfs(node->left, node->val);
            return left;
        } 
    }
};