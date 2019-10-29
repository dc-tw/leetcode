/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};
        vector<vector<int>> ans;    
        queue<Node*> q;
        q.push(root);
        int depth = 0;
        while (!q.empty()) {
            int size = q.size();
            ans.push_back({});
            while (size--) {
                Node* n = q.front(); q.pop();
                ans[depth].push_back(n->val);
                for (auto child : n->children) q.push(child);
            }
            ++depth;
        }
        return ans;
    }
};