class Solution {
    int best;
    int dfs(Node* u){
        if(!u) return 0;
        int L = max(0, dfs(u->left));
        int R = max(0, dfs(u->right));
        best = max(best, u->data + L + R);
        return u->data + max(L, R);
    }
  public:
    int findMaxSum(Node* root){
        best = INT_MIN;
        dfs(root);
        return best;
    }
};
