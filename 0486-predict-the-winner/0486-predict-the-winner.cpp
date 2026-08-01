class Solution {
public:
    vector<vector<int>> dp;
    int solve(int l,int r,vector<int>& nums){
        if(l==r) return nums[l];
        if(dp[l][r]!=INT_MIN) return dp[l][r];

        int takeleft=nums[l]-solve(l+1,r,nums);
        int takeright=nums[r]-solve(l,r-1,nums);
        return dp[l][r]=max(takeleft,takeright);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        dp.assign(n,vector<int>(n,INT_MIN));
        return solve(0,n-1,nums)>=0;
    }
};