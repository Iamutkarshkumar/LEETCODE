class Solution {
public:
    vector<vector<int>> directions{{0,1},{0,-1},{1,0},{-1,0}};
    bool isSafe(int x,int y,int r,int c){
        return x>=0 and x<r and y>=0 and y<c;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r=mat.size(),c=mat[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(mat[i][j]==0) q.push({i,j});
                else mat[i][j]=-1;
            }
        }
        int lvl=0;
        while(!q.empty()){
            int n=q.size();
            lvl++;
            while(n--){
                int ux=q.front().first;
                int uy=q.front().second;
                q.pop();
                for(auto dir: directions){
                    int vx=ux+dir[0];
                    int vy=uy+dir[1];
                    if(!isSafe(vx,vy,r,c)) continue;
                    if(mat[vx][vy]!=-1) continue;
                    mat[vx][vy]=lvl;
                    q.push({vx,vy});
                }
            }  
        }
        return mat;
    }
};