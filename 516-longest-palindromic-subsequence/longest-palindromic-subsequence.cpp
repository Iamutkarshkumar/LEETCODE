class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int L=1;L<=n;L++){
            for(int i=0;i+L-1<n;i++){
                int j=i+L-1;
                if(i==j) dp[i][i]=1;
                else if(s[i]==s[j]) dp[i][j] = 2+dp[i+1][j-1];
                else dp[i][j] = max(dp[i][j-1] , dp[i+1][j]);
            }
        }
        return dp[0][n-1];
    }
};
// class Solution {
// public:
//     int dp[1001][1001];
//     int solve(int i,int j,string& s){
//         if(i>j) return 0;
//         if(i==j) return 1;
//         if(dp[i][j]!=-1) return dp[i][j];
//         if(s[i]==s[j]) return dp[i][j]=2+solve(i+1,j-1,s);

//         int take_i_skip_j=solve(i,j-1,s);
//         int take_j_skip_i=solve(i+1,j,s);
//         return dp[i][j]= max(take_i_skip_j,take_j_skip_i);
//     }
//     int longestPalindromeSubseq(string s) {
//         memset(dp,-1,sizeof(dp));
//         int n=s.length();
//         return solve(0,n-1,s);
//     }
// };