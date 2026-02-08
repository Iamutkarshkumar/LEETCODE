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
    int getHeight(TreeNode* root){
        if(root==NULL) return 0;
        int leftHeight=getHeight(root->left);
        int rightHeigth=getHeight(root->right);
        return 1+max(leftHeight,rightHeigth);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int LH=getHeight(root->left);
        int RH=getHeight(root->right);
        if(abs(LH-RH)<=1 and isBalanced(root->left) and isBalanced(root->right)) return true;
        return false;
    }
};