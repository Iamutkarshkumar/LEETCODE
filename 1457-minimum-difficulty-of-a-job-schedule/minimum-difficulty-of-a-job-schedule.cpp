class Solution {
public:
    int dp[301][11];
    int solve(vector<int>& jd,int n,int idx,int d){
        if (d == 1) {
            return *max_element(begin(jd) + idx, end(jd));
        }
        if(dp[idx][d]!=-1) return dp[idx][d];
        int Max=INT_MIN;
        int result=INT_MAX;
        

        for (int i = idx; i <= n - d; i++) {
            Max = max(Max, jd[i]);
            result = min(result, Max + solve(jd, n, i + 1, d - 1));
        }
        
        return dp[idx][d]=result;
    }
    int minDifficulty(vector<int>& jd, int d) {
        memset(dp,-1,sizeof(dp));
        int n=jd.size();
        if(n<d) return -1;

        return solve(jd,n,0,d);
    }
};