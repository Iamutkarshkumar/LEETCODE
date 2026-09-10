class Solution {
    public:
    int validCount = 0;

    // Returns {sum of subtree, number of nodes in subtree}
    pair<int, int> dfs(TreeNode* node) {
        if (node == nullptr) return {0, 0};

        pair<int, int> left = dfs(node->left);
        pair<int, int> right = dfs(node->right);

        int currentSum = left.first + right.first + node->val;
        int currentCount = left.second + right.second + 1;

        // Check if the current node meets the average condition
        if (currentSum / currentCount == node->val) validCount++;
    
        return {currentSum, currentCount};
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return validCount;
    }
};