class Solution {
public:
    int dp[501][501];
    int solve(int i,int j,string& s){
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]) return dp[i][j]=solve(i+1,j-1,s);

        int take_i=1+solve(i,j-1,s);
        int take_j=1+solve(i+1,j,s);
        return dp[i][j]=min(take_i,take_j);
    }
    int minInsertions(string s) {
        memset(dp,-1,sizeof(dp));
        int n=s.length();
        return solve(0,n-1,s);
    }
};