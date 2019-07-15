/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        if (hash.count(node))
            return hash[node];
        Node* node_copy = new Node(node->val, {});
        hash[node] = node_copy;
        for (Node* n : node->neighbors) {
            node_copy->neighbors.push_back(cloneGraph(n));
        }
        return node_copy;
    }
private:
    unordered_map<Node*, Node*> hash;
};
/*
//bfs version
queue<Node*> q;
        q.push(node);
        unordered_map<Node*, Node*> hash;
        Node* node_copy = new Node(node->val, {});
        hash[node] = node_copy;
        while (!q.empty()) {
            Node* t = q.front(); q.pop();
            if (!t) continue;
            for (Node* n : t->neighbors) {
                if (!hash.count(n)) {
                    hash[n] = new Node(n->val, {});
                    q.push(n);
                }
                hasht]->neighbors.push_back(m_[n]);
            }
        }
        return node_copy;
*/