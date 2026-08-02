class Solution {
public:
    // int dp[501][501];
    vector<vector<int>> dp;
    int solve(int l,int r,vector<int>& piles){
        if(l>r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];

        int takeleft=piles[l]+min(solve(l+2,r,piles),solve(l+1,r-1,piles));
        int takeright=piles[r]+min(solve(l+1,r-1,piles),solve(l,r-2,piles));

        return dp[l][r]=max(takeleft,takeright);
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        // memset(dp,-1,sizeof(dp));
        dp.assign(n+1,vector<int>(n+1,-1));
        int total=0;
        for(int &ele: piles) total+=ele;
        int aliceStones = solve(0,n-1,piles);
        int bobStones = total-aliceStones;
        return aliceStones>bobStones;
        
    }
};