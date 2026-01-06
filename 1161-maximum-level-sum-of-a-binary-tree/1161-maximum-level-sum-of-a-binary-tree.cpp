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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int lvl=1,ans=1;
        long long mx=LLONG_MIN;

        while(!q.empty()){
            int n=q.size();
            long long sum=0;
            while(n--){
                TreeNode* t=q.front();q.pop();
                sum+=t->val;
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            if(sum>mx){
                mx=sum;
                ans=lvl;
            }
            lvl++;
        }
        return ans;
    }
};
