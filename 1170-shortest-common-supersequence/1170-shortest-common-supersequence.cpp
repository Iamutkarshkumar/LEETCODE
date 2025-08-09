class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int m=s1.length(),n=s2.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        // LCS dp table
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }

        // Build SCS from dp table
        int i=m, j=n;
        string res="";
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){ // part of LCS
                res.push_back(s1[i-1]);
                i--; j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                res.push_back(s1[i-1]);
                i--;
            }
            else{
                res.push_back(s2[j-1]);
                j--;
            }
        }

        // Add remaining characters
        while(i>0) res.push_back(s1[--i]);
        while(j>0) res.push_back(s2[--j]);

        reverse(res.begin(),res.end());
        return res;
    }
};
