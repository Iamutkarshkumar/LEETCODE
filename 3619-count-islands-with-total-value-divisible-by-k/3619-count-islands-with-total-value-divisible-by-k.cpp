class Solution {
public:
    using ll=long long;

    ll row,col;
    vector<vector<ll>> directions{{-1,0},{1,0},{0,-1},{0,1}};
    bool isSafe(ll x,ll y){
        return x>=0 and x<row and y>=0 and y<col;
    }
    ll bfs(ll x,ll y,vector<vector<int>>& grid){
        ll sum=0;
        queue<pair<ll,ll>> q;
        q.push({x,y});
        sum+=grid[x][y];
        grid[x][y]=0;

        while(!q.empty()){
            x=q.front().first;
            y=q.front().second;
            q.pop();

            for(auto &dir: directions){
                ll X=x+dir[0];
                ll Y=y+dir[1];

                if(!isSafe(X,Y) or grid[X][Y]==0) continue;

                sum+=grid[X][Y];
                grid[X][Y]=0;
                q.push({X,Y});
            }
        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        ll count=0;
        row=grid.size(),col=grid[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]!=0){
                    ll sum=bfs(i,j,grid);
                    if(sum%k==0) count++;
                }
            }
        }
        return count;
    }
};