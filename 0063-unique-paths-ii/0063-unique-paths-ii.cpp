class Solution {
public:
    int dp[101][101];
    int solve(int i,int j,int m,int n,vector<vector<int>>& obstacleGrid){
        if(i<0 or i>=m or j<0 or j>=n or obstacleGrid[i][j]==1) return 0;
        if(i==m-1 and j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int right=solve(i,j+1,m,n,obstacleGrid);
        int down=solve(i+1,j,m,n,obstacleGrid);
        return dp[i][j]=right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp,-1,sizeof(dp));
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        return solve(0,0,m,n,obstacleGrid);
    }
};
// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m = obstacleGrid.size();
//         int n = obstacleGrid[0].size();
//         vector<vector<int>> dp(m, vector<int>(n, 0));

//         // Start point
//         if (obstacleGrid[0][0] == 1) return 0;
//         dp[0][0] = 1;

//         // First column
//         for (int i = 1; i < m; i++) {
//             if (obstacleGrid[i][0] == 0 && dp[i-1][0] == 1)
//                 dp[i][0] = 1;
//         }

//         // First row
//         for (int j = 1; j < n; j++) {
//             if (obstacleGrid[0][j] == 0 && dp[0][j-1] == 1)
//                 dp[0][j] = 1;
//         }

//         // Fill the rest
//         for (int i = 1; i < m; i++) {
//             for (int j = 1; j < n; j++) {
//                 if (obstacleGrid[i][j] == 0)
//                     dp[i][j] = dp[i-1][j] + dp[i][j-1];
//             }
//         }

//         return dp[m-1][n-1];
//     }
// };
