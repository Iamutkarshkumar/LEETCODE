class Solution {
public:
    vector<vector<int>> directions{{1,1},{1,-1},{0,1},{1,0},{0,-1},{-1,1},{-1,0},{-1,-1}};
    bool isSafe(int m,int n,int x,int y){
        return x>=0 and x<m and y>=0 and y<n;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        if(m==0 or n==0 or grid[0][0]!=0) return -1;
        queue<pair<int,int>> que;
        que.push({0,0});
        grid[0][0]=1;
        int level=1;

        while(!que.empty()){
            int N=que.size();
            while(N--){
                auto curr=que.front();que.pop();

                int x=curr.first;
                int y=curr.second;

                if(x==m-1 and y==n-1) return level;

                for(auto dir: directions){
                    int x_=x+dir[0];
                    int y_=y+dir[1];
                    if(isSafe(m,n,x_,y_) and grid[x_][y_]==0) {
                        que.push({x_,y_});
                        grid[x_][y_]=1;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};