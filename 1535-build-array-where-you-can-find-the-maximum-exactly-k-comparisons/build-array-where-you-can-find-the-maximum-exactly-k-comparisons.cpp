class Solution {
public:
    const int MOD = 1000000007;
    int dp[51][51][101];
    int N,M,K;
    int solve(int idx,int searchCost,int maxSoFar){
        //base case
        if(idx==N){
            if(searchCost==K){
                return 1;
            }
            return 0;
        }
        if(dp[idx][searchCost][maxSoFar]!=-1) return dp[idx][searchCost][maxSoFar];
        int result=0;
        for(int i=1;i<=M;i++){
            if(i>maxSoFar){
                result=(result+solve(idx+1,searchCost+1,i))%MOD;
            }
            else result=(result+solve(idx+1,searchCost,maxSoFar))%MOD;
        }
        return dp[idx][searchCost][maxSoFar]=result%MOD;
    }
    int numOfArrays(int n, int m, int k) {
        N=n;
        M=m;
        K=k;
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0);
    }
};