class Solution {
public:
    vector<int> dp;
    int n;
    int solve(int i,vector<int>& prefix){
        if(i==n-1) return prefix[n-1];
        if(dp[i]!=INT_MIN) return dp[i];
        int take=prefix[i]-solve(i+1,prefix);
        int skip=solve(i+1,prefix);
        return dp[i]=max(take,skip);
    }
    int stoneGameVIII(vector<int>& stones) {
        n=stones.size();
        dp.assign(n,INT_MIN);
        vector<int> prefix(n,0);
        prefix[0]=stones[0];
        for(int i=1;i<n;i++) prefix[i]=prefix[i-1]+stones[i];
        return solve(1,prefix);
    }
};