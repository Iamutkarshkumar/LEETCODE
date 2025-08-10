class Solution {
public:
    int m,n;
    int dp[501][501];
    int solve(int i,int j, string& s1, string& s2){
        if(i==0) return j;
        if(j==0) return i;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i-1]==s2[j-1]) return dp[i][j]=solve(i-1,j-1,s1,s2);
        int ins = 1+ solve(i,j-1,s1,s2);
        int del = 1+solve(i-1,j,s1,s2);
        int rep = 1+solve(i-1,j-1,s1,s2);

        return dp[i][j] = min({ins,del,rep});

    }
    int minDistance(string s1, string s2) {
        m=s1.length();
        n=s2.length();
        memset(dp,-1,sizeof(dp));
        return solve(m,n,s1,s2);
    }
};
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