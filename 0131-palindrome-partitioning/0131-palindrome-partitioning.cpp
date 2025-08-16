class Solution {
public:
    void solve(string& s,int i,vector<vector<bool>>& dp,vector<string>& currPartition,vector<vector<string>>& result){
        if(i==s.length()){
            result.push_back(currPartition);
            return;
        }
        for(int j=i;j<s.length();j++){
            if(dp[i][j]){
                currPartition.push_back(s.substr(i,j-i+1));
                solve(s,j+1,dp,currPartition,result);
                currPartition.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n=s.length();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++) dp[i][i]=true;
        for(int L=2;L<=n;L++){
            for(int i=0;i+L-1<n;i++){
                int j=i+L-1;
                if(s[i]==s[j]){
                    if(L==2) dp[i][j]=true;
                    else dp[i][j]=dp[i+1][j-1];
                }
            }
        }

        vector<vector<string>> result;
        vector<string> currPartition;
        solve(s,0,dp,currPartition,result);
        return result;
    }
};