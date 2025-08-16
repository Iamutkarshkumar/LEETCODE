class Solution {
public:
    int minCut(string s) {
        int n=s.length();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int L=1;L<=n;L++){
            for(int i=0;i+L-1<n;i++){
                int j=i+L-1;
                if(i==j) dp[i][i]=true;
                else if(i+1==j and s[i]==s[j]) dp[i][i+1]=true;
                else dp[i][j] = (s[i]==s[j] and dp[i+1][j-1]);
            }
        }
        vector<int> dp1(n,INT_MAX);
        for(int i=0;i<n;i++){
            if(dp[0][i]) dp1[i]=0;
            else{
                for(int k=0;k<i;k++){
                    if(dp[k+1][i] and 1+dp1[k] < dp1[i]) dp1[i]=1+dp1[k];
                }
            }
        }
        return dp1[n-1];
    }
};
