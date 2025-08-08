class Solution {
public:
    const int MOD = 1000000007;
    int dp[51][51][101];
    int solve(int idx,int searchCost,int maxSoFar,int n, int m, int k){
        //base case
        if(idx==n){
            if(searchCost==k){
                return 1;
            }
            return 0;
        }
        if(maxSoFar!=-1 and dp[idx][searchCost][maxSoFar]!=-1) return dp[idx][searchCost][maxSoFar];
        int result=0;
        for(int i=1;i<=m;i++){
            if(i>maxSoFar){
                result=(result+solve(idx+1,searchCost+1,i,n,m,k))%MOD;
            }
            else result=(result+solve(idx+1,searchCost,maxSoFar,n,m,k))%MOD;
        }
        if(maxSoFar!=-1) return dp[idx][searchCost][maxSoFar]=result%MOD;
        return result%MOD;
    }
    int numOfArrays(int n, int m, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,-1,n,m,k);
    }
};