class Solution {
  private:
    void dfs(Node* node, vector<int> &res) {
        if (!node) return;
        dfs(node->left, res);        // traverse left subtree
        res.push_back(node->data);   // visit this node
        dfs(node->right, res);       // traverse right subtree
    }
    
  public:
    vector<int> inOrder(Node* root) {
        vector<int> res;
        dfs(root, res);
        return res;
    }
};
