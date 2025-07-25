// //1091. Shortest Path in Binary Matrix
// //bfs in a matrix
// class Solution {
// public:
//     vector<vector<int>>
//     directions{{1,1},{1,-1},{0,1},{1,0},{0,-1},{-1,1},{-1,0},{-1,-1}}; bool
//     isSafe(int m,int n,int x,int y){
//         return x>=0 and x<m and y>=0 and y<n;
//     }
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//         int m=grid.size(),n=grid[0].size();
//         if(m==0 or n==0 or grid[0][0]!=0) return -1;
//         queue<pair<int,int>> que;
//         que.push({0,0});
//         grid[0][0]=1;
//         int level=1;

//         while(!que.empty()){
//             int N=que.size();
//             while(N--){
//                 auto curr=que.front();que.pop();

//                 int x=curr.first;
//                 int y=curr.second;

//                 if(x==m-1 and y==n-1) return level;

//                 for(auto dir: directions){
//                     int x_=x+dir[0];
//                     int y_=y+dir[1];
//                     if(isSafe(m,n,x_,y_) and grid[x_][y_]==0) {
//                         que.push({x_,y_});
//                         grid[x_][y_]=1;
//                     }
//                 }
//             }
//             level++;
//         }
//         return -1;
//     }
// };

// Approach-2 (Using Dijkstra's Algorithm) - Using Priority_queue (min-heap)
class Solution {
public:
    using P = pair<int, pair<int, int>>;
    vector<vector<int>> directions{{1, 1},  {0, 1},   {1, 0},  {0, -1},
                                   {-1, 0}, {-1, -1}, {1, -1}, {-1, 1}};
    bool isSafe(int m, int n, int x, int y) {
        return x >= 0 and x < m and y >= 0 and y < n;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (m == 0 || n == 0 || grid[0][0] != 0)
            return -1;

        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;

        pq.push({0, {0, 0}});
        result[0][0] = 0;

        while (!pq.empty()) {
            int d = pq.top().first;
            pair<int, int> node = pq.top().second;
            pq.pop();

            int x = node.first;
            int y = node.second;

            for (auto dir : directions) {
                int x_ = x + dir[0];
                int y_ = y + dir[1];
                int dist = 1;

                if (isSafe(m, n, x_, y_) && grid[x_][y_] == 0 && d + dist < result[x_][y_]) {
                    pq.push({d + dist, {x_, y_}});
                    grid[x_][y_] = 1;
                    result[x_][y_] = d + dist;
                }
            }
        }

        if (result[m - 1][n - 1] == INT_MAX)
            return -1;

        return result[m - 1][n - 1] + 1;
    }
};