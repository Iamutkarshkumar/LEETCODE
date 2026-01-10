class Solution {
public:
    int m,n;
    int dp[1001][1001];
    int solve(int i,int j,string& s1,string& s2){
        if(i>=m and j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i>=m) return s2[j]+solve(i,j+1,s1,s2);
        if(j>=n) return s1[i]+solve(i+1,j,s1,s2);
        if(s1[i]==s2[j]) return solve(i+1,j+1,s1,s2);

        //two options
        int delete_s1_i= s1[i]+solve(i+1,j,s1,s2);
        int delete_s2_j= s2[j]+solve(i,j+1,s1,s2);
        return dp[i][j]=min(delete_s1_i,delete_s2_j);

    }
    int minimumDeleteSum(string s1, string s2) {
        memset(dp,-1,sizeof(dp));
        m=s1.length();
        n=s2.length();
        return solve(0,0,s1,s2);
    }
};