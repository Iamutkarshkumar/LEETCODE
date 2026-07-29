class Solution {
public:
    int r,c;
    int nonObs;
    int ans=0;
    
    bool isSafe(int i,int j){
        return (i>=0 and i<r and j>=0 and j<c);
    }
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};

    void backtrack(vector<vector<int>>& grid,int count,int i,int j){
        if(!isSafe(i,j) or grid[i][j]==-1) return;
        if(grid[i][j]==2){
            if(count==nonObs) ans++;
            return;
        }
        grid[i][j]=-1;
        for(auto &dir: directions){
            backtrack(grid,count+1,i+dir[0],j+dir[1]);
        }
        grid[i][j]=0;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        r=grid.size(),c=grid[0].size();

        nonObs=0;
        ans=0;
        int startX=-1,startY=-1;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==0) nonObs++;
                if(grid[i][j]==1){
                    nonObs++; // 1 is also non obsticle
                    startX=i;
                    startY=j;
                }
            }
        }

        backtrack(grid,0,startX,startY);
        return ans;
    }
};