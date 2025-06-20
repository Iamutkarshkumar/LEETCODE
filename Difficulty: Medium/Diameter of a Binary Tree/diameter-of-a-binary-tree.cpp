class Solution {
public:
    int diameter(Node* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
private:
    int dfs(Node* root, int &ans) {
        if (!root) return 0;
        int L = dfs(root->left,  ans);
        int R = dfs(root->right, ans);
        ans = max(ans, L + R);           
        return 1 + max(L, R);            
    }
};
