class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        bfs(root, 0, res);
        return res;
  }
private:
    void  bfs(TreeNode* root, int d, vector<int>& res) {
        if (!root) return;
        while (res.size() <= d) res.push_back(INT_MIN);    
        bfs(root->left, d + 1, res);
        res[d] = max(res[d], root->val);
        bfs(root->right, d + 1, res);
    }
};