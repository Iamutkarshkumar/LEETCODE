using ll=long long;
class Solution {
public:
    int n,m;
    vector<vector<ll>> dp;
    ll solve(int i,int j,vector<int>& robot,vector<int>& positions){
        if(i>=n) return 0;
        if(j>=m) return 1e18;
        if(dp[i][j]!=-1) return dp[i][j];

        ll take=abs(robot[i]-positions[j]) + solve(i+1,j+1,robot,positions);
        ll skip=solve(i,j+1,robot,positions);
        return dp[i][j]=min(take,skip);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        vector<int> positions;
        sort(begin(robot),end(robot));
        sort(begin(factory),end(factory));
        for(auto ele: factory){
            int pos=ele[0],limit=ele[1];
            while(limit--) positions.push_back(pos);
        }
        n=robot.size(),m=positions.size();
        dp.assign(n, vector<ll>(m, -1));
        return solve(0,0,robot,positions);
    }
};