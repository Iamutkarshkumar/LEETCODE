class Solution {
public:
    vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}}; //down, up, right, left
    bool isSafe(int m,int n,int x,int y){
        return x>=0 and x<m and y>=0 and y<n;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m= grid.size(); 
        int n= grid[0].size();
        queue<pair<int,int>> que;
        int freshCount = 0; //to count fresh oranges
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    que.push({i,j});
                }
                else if(grid[i][j]==1){
                    freshCount++;
                }
            }
        }
        if(freshCount == 0) return 0; //if no fresh oranges, return 0
        int ans=0;
        while(!que.empty()){
            int size = que.size();
            while(size--){
                int x=que.front().first;
                int y=que.front().second;
                que.pop();
                for(auto dir: directions){
                    int new_x= x + dir[0];
                    int new_y= y + dir[1];
                    if(isSafe(m,n,new_x,new_y) and grid[new_x][new_y]==1){
                        freshCount--; //decrease fresh count
                        grid[new_x][new_y]=2; //mark as rotten
                        que.push({new_x,new_y});
                    }
                }
            }
            ans++;
        }
        if(freshCount > 0) return -1; //if there are still fresh oranges left
        return ans-1;
    }
};