class Solution {
public:
    int minDistance(string s1, string s2) {
        int m=s1.length();
        int n=s2.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0 or j==0) dp[i][j]=i+j;
                else if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
                else{
                    int ins = 1+ dp[i][j-1];
                    int del = 1+ dp[i-1][j];
                    int rep = 1+ dp[i-1][j-1];
                    dp[i][j] = min({ins,del,rep});
                }
            }
        }
        return dp[m][n];
    }
};
// class Solution {
// public:
//     int m,n;
//     int dp[501][501];
//     int solve(int i,int j, string& s1, string& s2){
//         // if(i==0) return j;
//         // if(j==0) return i;
//         if(i==0 or j==0) return i+j;
//         if(dp[i][j]!=-1) return dp[i][j];
//         if(s1[i-1]==s2[j-1]) return dp[i][j]=solve(i-1,j-1,s1,s2);
//         int ins = 1+ solve(i,j-1,s1,s2);
//         int del = 1+solve(i-1,j,s1,s2);
//         int rep = 1+solve(i-1,j-1,s1,s2);

//         return dp[i][j] = min({ins,del,rep});

//     }
//     int minDistance(string s1, string s2) {
//         m=s1.length();
//         n=s2.length();
//         memset(dp,-1,sizeof(dp));
//         return solve(m,n,s1,s2);
//     }
// };
// class Solution {
// public:
//     int m,n;
//     int dp[501][501];
//     int solve(int i,int j, string& s1, string& s2){
//         if(i==m) return n-j;
//         if(j==n) return m-i;
//         if(dp[i][j]!=-1) return dp[i][j];
//         if(s1[i]==s2[j]) return dp[i][j]=solve(i+1,j+1,s1,s2);
//         int ins = 1+ solve(i,j+1,s1,s2);
//         int del = 1+solve(i+1,j,s1,s2);
//         int rep = 1+solve(i+1,j+1,s1,s2);

//         return dp[i][j] = min({ins,del,rep});

//     }
//     int minDistance(string s1, string s2) {
//         m=s1.length();
//         n=s2.length();
//         memset(dp,-1,sizeof(dp));
//         return solve(0,0,s1,s2);
//     }
// };