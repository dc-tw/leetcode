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
    unordered_map<int, vector<TreeNode*>> m;
    vector<TreeNode*> allPossibleFBT(int N) {
        if (N % 2 == 0) return {};
        if (N == 1) return {new TreeNode(0)};
        if (m.count(N)) return m[N];
        vector<TreeNode*> res;
        for (int i = 1; i < N; i += 2) {
            vector<TreeNode*> left = allPossibleFBT(i), right = allPossibleFBT(N - i - 1);
            for (auto a : left) {
                for (auto b : right) {
                    TreeNode *cur = new TreeNode(0);
                    cur->left = a;
                    cur->right = b;
                    res.push_back(cur);
                }
            }
        }
        return m[N] = res;
    }
};