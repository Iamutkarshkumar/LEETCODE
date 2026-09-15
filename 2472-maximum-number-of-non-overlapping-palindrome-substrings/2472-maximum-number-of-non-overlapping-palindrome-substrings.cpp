class Solution {
public: 
    int n;
    vector<vector<int>> dp;
    vector<vector<bool>> pal;

    int solve(string& s,int k,int i,int j){
        if(i>=n || j>=n) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int grow=solve(s,k,i,j+1);
        int slide=solve(s,k,i+1,j+1);

        if(pal[i][j]){
            int take=1+solve(s,k,j+1,j+k);
            return dp[i][j]=max({take,grow,slide});
        }

        return dp[i][j]=max(grow,slide);
    }

    int maxPalindromes(string s,int k) {
        n=s.size();

        dp.assign(n,vector<int>(n,-1));
        pal.assign(n,vector<bool>(n));

        for(int i=n-1;i>=0;i--)
            for(int j=i;j<n;j++)
                pal[i][j]=(s[i]==s[j] && (j-i<2 || pal[i+1][j-1]));

        return solve(s,k,0,k-1);
    }
};