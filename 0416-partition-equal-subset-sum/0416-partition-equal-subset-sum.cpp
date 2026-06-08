class Solution {
public:
    int dp[201][10001];
    bool solve(int n,int sum,vector<int>& nums){
        if(sum==0) return true;
        if(n==0) return false;
        if(dp[n][sum]!=-1) return dp[n][sum];
        bool skip=solve(n-1,sum,nums);
        bool take=false;
        if(nums[n-1]<=sum) take=solve(n-1,sum-nums[n-1],nums);
        return dp[n][sum]=(take or skip);
    }
    bool canPartition(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int sum=0;
        int n=nums.size();
        for(auto ele: nums) sum+=ele;
        if(sum&1) return false;
        sum/=2;
        return solve(n,sum,nums);
    }
};
// class Solution {
// public:
//     bool canPartition(vector<int>& nums) {
        
//     }
// };