// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         vector<vector<int>> dp(m,vector<int>(n));
//         dp[0][0]=grid[0][0];
//         for(int col=1;col<n;col++) dp[0][col]=grid[0][col]+dp[0][col-1];
//         for(int row=1;row<m;row++) dp[row][0]=grid[row][0]+dp[row-1][0];
//         for(int i=1;i<m;i++){
//             for(int j=1;j<n;j++){
//                 dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
//             }
//         }
//         return dp[m-1][n-1];
//     }
// };
class Solution {
public:
    int m,n;
    int dp[201][201];
    int solve(int i,int j,vector<vector<int>>& grid){
        if(i==m-1 and j==n-1) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==m-1) return  dp[i][j]= grid[i][j]+solve(i,j+1,grid);
        if(j==n-1) return  dp[i][j]= grid[i][j]+solve(i+1,j,grid);
        else return  dp[i][j]=grid[i][j]+min(solve(i+1,j,grid),solve(i,j+1,grid));
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        m=grid.size();
        n=grid[0].size();
        return solve(0,0,grid);
    }
};
