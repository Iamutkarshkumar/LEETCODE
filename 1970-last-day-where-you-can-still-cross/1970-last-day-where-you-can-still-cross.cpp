class Solution {
public:
    int ROW,COL;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool isSafe(int i,int j,int r,int c){
        return (i>=0 and j>=0 and i<r and j<c);
    }
    bool BFS(int i,int j,vector<vector<int>>& grid){
        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j]=1;
        while(!q.empty()){
            auto temp = q.front();q.pop();
            int x = temp.first;
            int y = temp.second;
            if(x==ROW-1) return true;
            for(auto dir: directions){
                int new_x=x+dir[0];
                int new_y=y+dir[1];
                if(isSafe(new_x,new_y,ROW,COL) and grid[new_x][new_y]==0){
                    q.push({new_x,new_y});
                    grid[new_x][new_y]=1;
                }
            }
        }
        return false;
    }
    bool canCross(int m,vector<vector<int>>& cells){
        vector<vector<int>> grid(ROW,vector<int>(COL,0));
        for(int i=0;i<=m;i++){
            int r=cells[i][0]-1;
            int c=cells[i][1]-1;
            grid[r][c]=1;
        }
        for(int j=0;j<COL;j++){
            if(grid[0][j]==0 and BFS(0,j,grid)) return true;
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        ROW=row;
        COL=col;
        int l=0,r=cells.size();
        int ans;
        while(l<=r){
            int m=l+(r-l)/2;
            if(canCross(m,cells)){
                ans=m+1;
                l=m+1;
            }
            else r=m-1;
        }
        return ans;
    }
};