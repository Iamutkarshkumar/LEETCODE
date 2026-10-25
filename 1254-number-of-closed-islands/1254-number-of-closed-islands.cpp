class Solution {
public:
    int row,col;
    vector<vector<int>> direction{{-1,0},{1,0},{0,1},{0,-1}};
    bool isSafe(int x,int y){
        return x>=0 and x<row and y>=0 and y<col;
    }
    void bfs(int x,int y,vector<vector<int>>& grid){
        queue<pair<int,int>> q;
        q.push({x,y});
        while(!q.empty()){
            x=q.front().first;
            y=q.front().second;
            grid[x][y]=1;
            q.pop();
            for(auto &dir: direction){
                int X=x+dir[0];
                int Y=y+dir[1];
                if(!isSafe(X,Y) or grid[X][Y]==1) continue;
                q.push({X,Y});
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        row=grid.size(),col=grid[0].size();

        // for(int i=0;i<row;i++){
        //     for(int j=0;j<col;j++){
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        
        for(int i=0;i<col;i++){
            if(grid[0][i]==0) bfs(0,i,grid);
        }
        for(int i=0;i<col;i++){
            if(grid[row-1][i]==0) bfs(row-1,i,grid);
        }
        for(int i=0;i<row;i++){
            if(grid[i][0]==0) bfs(i,0,grid);
        }
        for(int i=0;i<row;i++){
            if(grid[i][col-1]==0) bfs(i,col-1,grid);
        }
        // for(int i=0;i<row;i++){
        //     for(int j=0;j<col;j++){
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // return 0;
        int ans=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==0){
                    ans++;
                    bfs(i,j,grid);
                }
            }
        }
        return ans;  
    }
};