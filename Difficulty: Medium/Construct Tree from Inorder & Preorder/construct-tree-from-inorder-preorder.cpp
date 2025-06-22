class Solution {
  public:
    Node* buildTree(vector<int> &inorder, vector<int> &preorder) {
        int n = inorder.size(), preIdx = 0;
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++) mp[inorder[i]] = i;
        function<Node*(int,int)> build = [&](int l, int r)->Node* {
            if(l > r) return NULL;
            int v = preorder[preIdx++];
            Node* root = new Node(v);
            int m = mp[v];
            root->left  = build(l,   m - 1);
            root->right = build(m + 1, r);
            return root;
        };
        return build(0, n - 1);
    }
};
