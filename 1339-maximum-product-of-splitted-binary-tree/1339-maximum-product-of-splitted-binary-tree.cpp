/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long ans = 0;
    long long totalSum = 0;

    long long sumOfSubTree(TreeNode* root){
        if(!root) return 0;
        return root->val + sumOfSubTree(root->left) + sumOfSubTree(root->right);
    }

    long long dfs(TreeNode* root){
        if(!root) return 0;

        long long left = dfs(root->left);
        long long right = dfs(root->right);

        long long subSum = root->val + left + right;

        ans = max(ans, subSum * (totalSum - subSum));
        return subSum;
    }

    int maxProduct(TreeNode* root) {
        totalSum = sumOfSubTree(root);  // first pass
        dfs(root);                      // second pass
        return ans % 1000000007;
    }
};
