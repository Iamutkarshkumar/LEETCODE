// class Solution {
// public:
//     int r,c;

//     bool isSafe(int x,int y){
//         return x>=0 and x<r and y>=0 and y<c;
//     }
//     int dp[101][101][200];
//     bool solve(int i,int j,int count,vector<vector<char>>& grid){
//         if(count<0) return false;

//         if(i==r-1 and j==c-1) return count==0;
        
//         if(dp[i][j][count]!=-1) return dp[i][j][count];
//         bool right=false,down=false;

//         if(isSafe(i,j+1)){
//             if(grid[i][j+1]=='(') right=solve(i,j+1,count+1,grid);
//             else right=solve(i,j+1,count-1,grid);
//         }

//         if(isSafe(i+1,j)){
//             if(grid[i+1][j]=='(') down=solve(i+1,j,count+1,grid);
//             else down=solve(i+1,j,count-1,grid);
//         }

//         return dp[i][j][count]=right or down;
//     }

//     bool hasValidPath(vector<vector<char>>& grid) {
//         r=grid.size(),c=grid[0].size();
//         memset(dp,-1,sizeof(dp));
//         if(grid[0][0]!= '(' or grid[r-1][c-1]!=')') return false;

//         return solve(0,0,1,grid);
//     }
// };
class Solution {
public:
    int r,c;
    int dp[101][101][202];

    bool solve(int i,int j,int count,vector<vector<char>>& grid){
        if(i>=r or j>=c or count<0) return false;

        if(i==r-1 and j==c-1){
            if(grid[i][j]=='(') count++;
            else count--;
            return count==0;
        }

        if(dp[i][j][count]!=-1) return dp[i][j][count];

        bool ans;

        if(grid[i][j]=='(')
            ans=solve(i+1,j,count+1,grid) or solve(i,j+1,count+1,grid);
        else
            ans=solve(i+1,j,count-1,grid) or solve(i,j+1,count-1,grid);

        return dp[i][j][count]=ans;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        r=grid.size(),c=grid[0].size();

        if((r+c-1)%2 or grid[0][0]!= '(' or grid[r-1][c-1]!=')')
            return false;

        memset(dp,-1,sizeof(dp));

        return solve(0,0,0,grid);
    }
};