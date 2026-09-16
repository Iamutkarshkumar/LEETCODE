class Solution {
public:
    const int MOD=1e9+7;
    vector<vector<int>> dp;

    int solve(int i,int k,int n){
        if(k==0) return 1;
        if(i==n) return 0;

        if(dp[i][k]!=-1) return dp[i][k];

        int take=solve(i+1,k-1,n);
        int skip=solve(i+1,k,n);

        return dp[i][k]=(take+skip)%MOD;
    }

    int numberOfSets(int n,int k){
        dp.assign(n+k,vector<int>(2*k+1,-1));
        return solve(0,2*k,n+k-1);
    }
};