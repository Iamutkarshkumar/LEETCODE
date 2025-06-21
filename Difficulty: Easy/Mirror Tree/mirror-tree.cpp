class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        if (!node) return;
        // swap children
        Node* tmp = node->left;
        node->left  = node->right;
        node->right = tmp;
        // recurse on subtrees
        mirror(node->left);
        mirror(node->right);
    }
};
