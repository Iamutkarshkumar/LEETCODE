class Solution {
public:
    int n,m;
    vector<vector<int>> dp;
    int solve(int i,int j,string& s,string& t){
        //base case
        if(j==m) return 1;
        if(i==n) return 0;
        //memoization 
        if(dp[i][j]!=-1) return dp[i][j];

        int skip=solve(i+1,j,s,t);
        int take=0;
        if(s[i]==t[j]) take=solve(i+1,j+1,s,t);

        return dp[i][j]=take+skip;
    }
    int numDistinct(string s, string t) {
        n=s.length();
        m=t.length();
        dp.assign(n,vector<int>(m,-1));
        return solve(0,0,s,t);
    }
};