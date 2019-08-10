/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        serialize(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        return deserialize(data, pos);
    }
private:
    enum STATUS {
        ROOT_NULL = 0x0,
        ROOT = 0x1,
        LEFT = 0x2,
        RIGHT = 0x4
    };
    
    void serialize(TreeNode* root, string& s) {
        char status = ROOT_NULL;
        if (root) status |= ROOT;
        if (root && root->left) status |= LEFT;
        if (root && root->right) status |= RIGHT;
        s.push_back(status);
        if (!root) return;
        s.append(reinterpret_cast<char*>(&root->val), sizeof(root->val));
        if (root->left) serialize(root->left, s);
        if (root->right) serialize(root->right, s);
    }
    
    TreeNode* deserialize(const string& s, int& pos) {
        char status = s[pos++];
        if (!status) return nullptr;
        TreeNode* root = new TreeNode(0);
        memcpy(&root->val, s.data() + pos, sizeof(root->val));
        pos += sizeof(root->val);  
        root->left = (status & LEFT) ? deserialize(s, pos) : nullptr;
        root->right = (status & RIGHT) ? deserialize(s, pos) : nullptr;
        return root;
    }
};