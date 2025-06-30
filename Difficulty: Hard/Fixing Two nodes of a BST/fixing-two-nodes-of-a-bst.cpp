class Solution {
    Node *first, *middle, *last, *prev;
    void dfs(Node* root) {
        if (!root) return;
        dfs(root->left);
        if (prev && root->data < prev->data) {
            if (!first) {
                first = prev;
                middle = root;
            } else {
                last = root;
            }
        }
        prev = root;
        dfs(root->right);
    }
  public:
    void correctBST(Node* root) {
        first = middle = last = prev = nullptr;
        dfs(root);
        if (first && last)
            std::swap(first->data, last->data);
        else if (first && middle)
            std::swap(first->data, middle->data);
    }
};
