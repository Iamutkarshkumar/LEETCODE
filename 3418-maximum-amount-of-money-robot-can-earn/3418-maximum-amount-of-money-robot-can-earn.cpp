class Solution {
public:
    int m,n;
    // Move right and down
    vector<pair<int,int>> directions = {{0,1},{1,0}};
    bool isSafe(int x,int y,int m,int n){
        return (x>=0 and x<m and y>=0 and y<n);
    }
    int solve(int i,int j,int k,vector<vector<int>>& coins,vector<vector<vector<int>>>& dp){
        if(!isSafe(i,j,m,n)) return -1e9;

        if(i==m-1 and j==n-1){
            if(coins[i][j]>=0) return coins[i][j];
            else{
                if(k>0) return 0;
                else return coins[i][j];
            }
        }

        if(dp[i][j][k]!=-1e9) return dp[i][j][k];

        int ans=-1e9;
        
        for(auto dir: directions){
            int ni=i+dir.first,nj=j+dir.second;
            if(coins[i][j]>=0) ans=max(ans,coins[i][j]+solve(ni,nj,k,coins,dp));
            else{
                //option 1 : take loss
                ans=max(ans,coins[i][j]+solve(ni,nj,k,coins,dp));
                //option 2 : neutralize
                if(k>0){
                    ans=max(ans,solve(ni,nj,k-1,coins,dp));
                }
            }
        }
        return dp[i][j][k]=ans;
    }
    int maximumAmount(vector<vector<int>>& coins) {
        m=coins.size(),n=coins[0].size();
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(3, -1e9)));
        return solve(0,0,2,coins,dp);
    }
};