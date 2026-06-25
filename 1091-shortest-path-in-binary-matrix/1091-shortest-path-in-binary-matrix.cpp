//using BFS
// class Solution {
// public:
//     vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
//     bool isSafe(int x,int y,int m,int n){
//         return (x>=0 and x<m and y>=0 and y<n);
//     }
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//         int n=grid.size();
//         if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
//         queue<pair<int,int>> q;
//         q.push({0,0});
//         grid[0][0]=1;
//         int levels=0;
//         while(!q.empty()){
//             int l=q.size();
//             while(l--){
//                 int x=q.front().first;
//                 int y=q.front().second;
//                 q.pop();
//                 if(x==n-1 and y==n-1) return levels+1; // levels + cell (0,0) = clear path
//                 for(auto dir: directions){
//                     int newX = x+dir[0];
//                     int newY = y+dir[1];
//                     if(isSafe(newX,newY,n,n) and grid[newX][newY]==0){
//                         q.push({newX,newY});
//                         grid[newX][newY]=1;
//                     }
//                 }
//             }
//             levels++;
//         }
//         return -1;
//     }
// };

//using dijkstra's algo
using P = pair<int,pair<int,int>>;
class Solution {
public:
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
    bool isSafe(int x,int y,int m,int n){
        return (x>=0 and x<m and y>=0 and y<n);
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        priority_queue<P,vector<P>,greater<P>> pq;
        vector<vector<int>> result(n,vector<int>(n,INT_MAX));
        pq.push({0,{0,0}});
        result[0][0]=0;

        while(!pq.empty()){
            int ux=pq.top().second.first;
            int uy=pq.top().second.second;
            int d=pq.top().first;
            pq.pop();
            for(auto dir: directions){
                int newx = ux+dir[0];
                int newy = uy+dir[1];
                int dist=1;
                if(isSafe(newx,newy,n,n) and grid[newx][newy]==0){
                    if(d+dist<result[newx][newy]){
                        pq.push({d+dist,{newx,newy}});
                        grid[newx][newy]=1;
                        result[newx][newy]=d+dist;
                    }
                }
            }
        }
        return result[n-1][n-1]==INT_MAX ? -1 : result[n-1][n-1]+1;
    }
};