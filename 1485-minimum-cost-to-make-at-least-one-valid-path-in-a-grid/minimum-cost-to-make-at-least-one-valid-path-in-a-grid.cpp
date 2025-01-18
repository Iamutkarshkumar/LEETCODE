class Solution {
public:
    int n,m;
    int dp[105][105];
    bool isValid(int x,int y){
        return (x>=0 and x<n and y>=0 and y<m);
    }
    int minCost(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<pair<int,int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
        memset(dp,1000000,sizeof(dp));
        dp[0][0]=0;
        queue<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            int x=curr.first,y=curr.second;
            for(int i=0;i<4;i++){
                int X=x+dir[i].first;
                int Y=y+dir[i].second;
                if(isValid(X,Y)){
                    if(i+1 == grid[x][y] and dp[X][Y]>dp[x][y]){
                        dp[X][Y]=dp[x][y];
                        q.push({X,Y});
                    }
                    else if(dp[x][y]+1<dp[X][Y]){
                        dp[X][Y]=dp[x][y]+1;
                        q.push({X,Y});
                    }
                }
            }
        }
        return dp[n-1][m-1];
    }
};