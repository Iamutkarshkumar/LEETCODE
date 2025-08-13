class Solution {
public:
    int dp[1001][1001];
    int solve(int i,int j,string& s){
        if(i>j) return 0;
        if(i==j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]) return dp[i][j]=2+solve(i+1,j-1,s);

        int take_i_skip_j=solve(i,j-1,s);
        int take_j_skip_i=solve(i+1,j,s);
        return dp[i][j]= max(take_i_skip_j,take_j_skip_i);
    }
    int longestPalindromeSubseq(string s) {
        memset(dp,-1,sizeof(dp));
        int n=s.length();
        return solve(0,n-1,s);
    }
};