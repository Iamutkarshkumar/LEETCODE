// class Solution {
// public:
//     int dp[201][10001];
//     bool solve(int n,int sum,vector<int>& nums){
//         if(sum==0) return true;
//         if(n==0) return false;
//         if(dp[n][sum]!=-1) return dp[n][sum];
//         bool skip=solve(n-1,sum,nums);
//         bool take=false;
//         if(nums[n-1]<=sum) take=solve(n-1,sum-nums[n-1],nums);
//         return dp[n][sum]=(take or skip);
//     }
//     bool canPartition(vector<int>& nums) {
//         memset(dp,-1,sizeof(dp));
//         int sum=0;
//         int n=nums.size();
//         for(auto ele: nums) sum+=ele;
//         if(sum&1) return false;
//         sum/=2;
//         return solve(n,sum,nums);
//     }
// };
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto ele: nums) sum+=ele;
        if(sum&1) return false;
        sum/=2;
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
        for(int i=0;i<n+1;i++) dp[i][0]=true;

        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                bool skip=dp[i-1][j];
                bool take=false;
                if(nums[i-1]<=j) take=dp[i-1][j-nums[i-1]];
                dp[i][j]=(take or skip);
            }
        }
        return dp[n][sum];
    }
};