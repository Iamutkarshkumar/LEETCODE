class Solution {
public:
    int dp[1001][1001];
    int solve(int i,int p,vector<vector<int>>& pairs){
        if(i>=pairs.size()) return 0;
        if(p!=-1 and dp[i][p]!=-1) return dp[i][p];

        //take
        int take=0;
        if(p==-1 or pairs[p][1]<pairs[i][0]){
            take=1+solve(i+1,i,pairs);
        }
        //skip
        int skip= solve(i+1,p,pairs);

        if(p!=-1) dp[i][p] = max(take,skip);
        return max(take,skip);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(begin(pairs),end(pairs));
        memset(dp,-1,sizeof(dp));
        return solve(0,-1,pairs);
    }
};