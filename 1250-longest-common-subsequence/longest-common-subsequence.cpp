class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int m=s1.length(),n=s2.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};
// class Solution {
// public:
//     int dp[1001][1001];
//     int solve(int i,int j,string &text1, string &text2){
//         if(i>=text1.length() or j>=text2.length()) return 0;
//         if(dp[i][j]!=-1) return dp[i][j];
//         if(text1[i]==text2[j]) return dp[i][j]=1+solve(i+1,j+1,text1,text2);

//         int take1skip2=solve(i,j+1,text1,text2);
//         int take2skip1=solve(i+1,j,text1,text2);
//         return dp[i][j]=max(take1skip2,take2skip1);
//     }
//     int longestCommonSubsequence(string text1, string text2) {
//         memset(dp,-1,sizeof(dp));
//         return solve(0,0,text1,text2);
//     }
// };