class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n,1);
        int ans=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    dp[i] = max(dp[i],dp[j]+1);
                    ans=max(ans,dp[i]);
                }
            }
        }
        return ans;
    }
};
// class Solution {
// public:
//     int dp[2501][2501];
//     int solve(int i, int p ,vector<int>& nums){
//         if(i>=nums.size()) return 0;
//         if(p!=-1 and dp[i][p]!=-1) return dp[i][p];
//         //take
//         int take=0;
//         if(p==-1 or nums[p]<nums[i]){
//             take = 1+solve(i+1,i,nums);
//         }

//         // skip
//         int skip = solve(i+1,p,nums);
//         if(p!=-1) dp[i][p]=max(take,skip);
//         return max(take,skip);
//     }
//     int lengthOfLIS(vector<int>& nums) {
//         memset(dp,-1,sizeof(dp));
//         return solve(0,-1,nums);
//     }
// };