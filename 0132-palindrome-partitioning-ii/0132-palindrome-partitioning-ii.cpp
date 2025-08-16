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
        vector<int> cuts(n,INT_MAX);
        for(int i=0;i<n;i++){
            if(dp[0][i]) {cuts[i]=0; continue;}
            for(int j=0;j<i;j++){
                if(dp[j+1][i]) cuts[i]=min(cuts[i],cuts[j]+1);
            }
        }
        return cuts[n-1];
    }
};