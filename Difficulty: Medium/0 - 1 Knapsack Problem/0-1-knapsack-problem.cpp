class Solution {
  public:
    int dp[1001][1001];
    int solve(int n,int W,vector<int> &val, vector<int> &wt){
        if(n<=0 or W==0) return 0;
        if(dp[n][W]!=-1) return dp[n][W];
        int take=0,skip=0;
        if(wt[n-1]<=W) take=val[n-1]+solve(n-1,W-wt[n-1],val,wt);
        skip=solve(n-1,W,val,wt);
        return dp[n][W]=max(take,skip);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        memset(dp,-1,sizeof(dp));
        int n=val.size();
        return solve(n,W,val,wt);
        
    }
};