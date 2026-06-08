class Solution {
  public:
    int dp[201][10001];
    bool solve(int n,vector<int>& arr, int sum){
        if(sum==0) return true;
        if(n==0) return false;
        if(dp[n][sum]!=-1) return dp[n][sum];
        bool skip=solve(n-1,arr,sum);
        bool take=false;
        if(arr[n-1]<=sum) take=solve(n-1,arr,sum-arr[n-1]);
        return dp[n][sum]=(skip or take);
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        memset(dp,-1,sizeof(dp));
        int n=arr.size();
        return solve(n,arr,sum);
        
    }
};