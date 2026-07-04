// approach 1: 0-1 BFS
class Solution {
public:
    using P=pair<int,pair<int,int>>;
    vector<vector<int>> directions{{0,1},{0,-1},{1,0},{-1,0}};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int r=grid.size(),c=grid[0].size();
        vector<vector<int>> result(r,vector<int>(c,INT_MAX));
        deque<P> dq;
        result[0][0]=grid[0][0];
        dq.push_front({result[0][0],{0,0}});
        while(!dq.empty()){
            int cost=dq.front().first;
            int ux=dq.front().second.first;
            int uy=dq.front().second.second;
            dq.pop_front();
            for(auto &dir: directions){
                int vx=ux+dir[0];
                int vy=uy+dir[1];
                if(!(vx>=0 and vx<r and vy>=0 and vy<c)) continue;
                int wt=grid[vx][vy];
                if(cost+wt<result[vx][vy]){
                    result[vx][vy]=cost+wt;
                    if(wt==0) dq.push_front({cost+wt,{vx,vy}});
                    else dq.push_back({cost+wt,{vx,vy}});
                }
            }
        }
        if(result[r-1][c-1]==INT_MAX or result[r-1][c-1]>=health) return false;
        return true;
    }
};

// appraoch 2: dijkstra's 
// using P=pair<int,pair<int,int>>;
// class Solution {
// public:
//     vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
//     bool isSafe(int x,int y,int r,int c){
//         return x>=0 and x<r and y>=0 and y<c;
//     }
//     bool findSafeWalk(vector<vector<int>>& grid, int health) {
//         int r=grid.size(),c=grid[0].size();
//         vector<vector<int>> result(r,vector<int>(c,INT_MAX));
//         priority_queue<P,vector<P>,greater<P>> pq;
//         result[0][0]=grid[0][0];
//         pq.push({result[0][0],{0,0}});
//         while(!pq.empty()){
//             int ux=pq.top().second.first;
//             int uy=pq.top().second.second;
//             int w=pq.top().first;
//             pq.pop();
//             if(w>result[ux][uy]) continue;
//             for(auto dir: directions){
//                 int vx=ux+dir[0];
//                 int vy=uy+dir[1];
//                 if(!isSafe(vx,vy,r,c)) continue;
//                 int wt=grid[vx][vy];
//                 if(wt+w<result[vx][vy]){
//                     pq.push({wt+w,{vx,vy}});
//                     result[vx][vy]=wt+w;
//                 }
//             }
//         }
//         if(result[r-1][c-1]<health) return true;
//         return false;
//     }
// };