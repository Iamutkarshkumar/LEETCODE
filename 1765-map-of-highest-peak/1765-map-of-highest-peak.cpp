class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        vector<vector<int>> directions{{0,1},{0,-1},{1,0},{-1,0}};
        int r=isWater.size(),c=isWater[0].size();
        vector<vector<int>> heights(r,vector<int>(c,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(isWater[i][j]==1) {
                    q.push({i,j});
                    heights[i][j]=0;
                }
            }
        }
        int lvl=1;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                int ux=q.front().first;
                int uy=q.front().second;
                q.pop();
                for(auto &dir: directions){
                    int vx=ux+dir[0];
                    int vy=uy+dir[1];
                    if(!(vx>=0 and vx<r and vy>=0 and vy<c)) continue;
                    if(heights[vx][vy]!=-1) continue;
                    heights[vx][vy]=lvl;
                    q.push({vx,vy});
                }
            }
            lvl++;
        }
        return heights;
    }
};