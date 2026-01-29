class Solution {
public:
    int dp[305][305];
    int solve(int l,int r,vector<int>& nums){
        if(r-l<=1) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        int ans=0;
        for(int k=l+1;k<r;k++) ans=max(ans,solve(l,k,nums)+nums[l]*nums[k]*nums[r]+solve(k,r,nums));
        return dp[l][r]=ans;
    }
    int maxCoins(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        nums.insert(begin(nums),1);
        nums.push_back(1);
        int n=nums.size();
        return solve(0,n-1,nums);
    }
};