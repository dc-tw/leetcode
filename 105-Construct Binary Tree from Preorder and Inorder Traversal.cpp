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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root;
        if (preorder.size() == 0) {
            return NULL;
        }
        root = helper(root, preorder, 0, preorder.size() - 1, inorder, 0, preorder.size() - 1);

        return root;
    }

    TreeNode* helper(TreeNode* root, vector<int>& preorder, int start1, int end1, vector<int>& inorder, int start2, int end2) {
        if (end1 < start1) {
            return root;
        } 
        else {
            root = new TreeNode(preorder[start1]);
            int i = 0;
            for (; i < end2-start2; i++) {
                if (inorder[i+start2] == preorder[start1]) {
                    break;
                }
            }

            root->left = (i < 1) ? NULL : helper(root->left, preorder, start1 + 1, i+start1, inorder, start2, start2 + i - 1);
            root->right = (i + start1 + 1 > end1) ? NULL : helper(root->right, preorder, i+start1 + 1, end1, inorder, i+start2 + 1, end2);
            return root;
        }
    }
};