class Solution {
public:
    vector<vector<int>> directions{{1,0},{0,1},{0,-1},{-1,0}};
    bool isSafe(int x,int y,int m,int n){
        return x>=0 and y>=0 and x<m and y<n;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        queue<pair<int,int>> q;
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<bool>> po(m,vector<bool>(n,false));
        vector<vector<bool>> ao(m,vector<bool>(n,false));
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            q.push({0,i});
            po[0][i]=true;
        }
        for(int i=0;i<m;i++){
            q.push({i,0});
            po[i][0]=true;
        }
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(auto dir: directions){
                int new_x=dir[0]+x;
                int new_y=dir[1]+y;
                if(!isSafe(new_x,new_y,m,n) or po[new_x][new_y]) continue;
                if(heights[new_x][new_y]>=heights[x][y]){
                    q.push({new_x,new_y});
                    po[new_x][new_y]=true;
                }
            }
        }
        q = queue<pair<int,int>>();
        for(int i=0;i<n;i++){
            q.push({m-1,i});
            ao[m-1][i]=true;
        }
        for(int i=0;i<m;i++){
            q.push({i,n-1});
            ao[i][n-1]=true;
        }
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(auto dir: directions){
                int new_x=dir[0]+x;
                int new_y=dir[1]+y;
                if(!isSafe(new_x,new_y,m,n) or ao[new_x][new_y]) continue;
                if(heights[new_x][new_y]>=heights[x][y]){
                    q.push({new_x,new_y});
                    ao[new_x][new_y]=true;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(po[i][j] and ao[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};