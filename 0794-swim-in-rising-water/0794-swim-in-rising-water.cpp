class Solution {
public:
    using P = pair<int,pair<int,int>>;
    vector<vector<int>> dirs{{1,0},{-1,0},{0,1},{0,-1}};
    bool inb(int n,int x,int y){ return x>=0 && x<n && y>=0 && y<n; }
    int swimInWater(vector<vector<int>>& grid){
        int n=grid.size();
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        priority_queue<P,vector<P>,greater<P>> pq;
        dist[0][0]=grid[0][0];
        pq.push({grid[0][0],{0,0}});
        while(!pq.empty()){
            int t=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            if(t>dist[x][y]) continue;            // stale entry
            if(x==n-1 && y==n-1) return t;        // reached target, minimal t
            for(auto &d:dirs){
                int nx=x+d[0], ny=y+d[1];
                if(!inb(n,nx,ny)) continue;
                int nt = max(t, grid[nx][ny]);
                if(nt < dist[nx][ny]){
                    dist[nx][ny]=nt;
                    pq.push({nt,{nx,ny}});
                }
            }
        }
        return dist[n-1][n-1];
    }
};
