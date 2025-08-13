class Solution {
public:
    int minInsertions(string s) {
        int n=s.length();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int L=2;L<=n;L++){
            for(int i=0;i+L-1<n;i++){
                int j=i+L-1;
                if(s[i]==s[j]) dp[i][j]=dp[i+1][j-1];
                else dp[i][j] = min(1+dp[i][j-1] , 1+dp[i+1][j]);
            }
        }
        return dp[0][n-1];
    }
};
// class Solution {
// public:
//     int dp[501][501];
//     int solve(int i,int j,string& s){
//         if(i>=j) return 0;
//         if(dp[i][j]!=-1) return dp[i][j];
//         if(s[i]==s[j]) return dp[i][j]=solve(i+1,j-1,s);

//         int take_i=1+solve(i,j-1,s);
//         int take_j=1+solve(i+1,j,s);
//         return dp[i][j]=min(take_i,take_j);
//     }
//     int minInsertions(string s) {
//         memset(dp,-1,sizeof(dp));
//         int n=s.length();
//         return solve(0,n-1,s);
//     }
// };