/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        while(root != NULL )
        {
            S.push(root);
            root = root->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        int result = 0;
        if(!S.empty())
        {
            TreeNode* node = S.top();
            result = node->val;
            S.pop();
            node = node->right;
            while(node != NULL)
            {
                S.push(node);
                node = node->left;
            }
        }
        return result;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(S.size() > 0)
            return true;
        return false;
    }
    private:
    std::stack<TreeNode*> S;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */