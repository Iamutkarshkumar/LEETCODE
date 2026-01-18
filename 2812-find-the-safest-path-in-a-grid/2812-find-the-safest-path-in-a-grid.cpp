// class Solution {
// public:
//     int n;
//     vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};

//     bool check(vector<vector<int>>& nearestThief, int m){
//         queue<pair<int,int>> q;
//         vector<vector<bool>> visited(n,vector<bool>(n,false));
//         q.push({0,0});
//         visited[0][0]=true;
//         if(nearestThief[0][0]<m) return false;
//         while(!q.empty()){
//             int x=q.front().first;
//             int y=q.front().second;
//             q.pop();
//             if(x==n-1 and y==n-1) return true;
//             for(auto dir: directions){
//                 int newX=x+dir[0];
//                 int newY=y+dir[1];
//                 if(newX>=0 and newX<n and newY>=0 and newY<n and visited[newX][newY]==false){
//                     if(nearestThief[newX][newY]<m) continue;

//                     q.push({newX,newY});
//                     visited[newX][newY]=true;
//                 }
//             }
//         }
//         return false;
//     }
//     int maximumSafenessFactor(vector<vector<int>>& grid) {

//         //multi source BFS
//         n=grid.size();
//         vector<vector<int>> nearestThief(n,vector<int>(n,-1));
//         queue<pair<int,int>> q;
//         vector<vector<bool>> visited(n,vector<bool>(n,false));

//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 if(grid[i][j]==1){
//                     q.push({i,j});
//                     visited[i][j]=true;
//                 }
//             }
//         }

//         int lvl=0;
//         while(not q.empty()){
//             int size=q.size();
//             while(size--){
//                 int x=q.front().first;
//                 int y=q.front().second;
//                 q.pop();
//                 nearestThief[x][y]=lvl;
//                 for(auto dir: directions){
//                     int newX = x+dir[0];
//                     int newY = y+dir[1];

//                     if(newX < 0 || newX >= n || newY < 0 || newY >= n || visited[newX][newY]) {
//                         continue;
//                     }
//                     q.push({newX,newY});
//                     visited[newX][newY]=true;
//                 }
//             }
//             lvl++;
//         }

//         // binary search on answer
//         int l=0,r=n*2;
//         int ans=0;
//         while(l<=r){
//             int m=l+(r-l)/2;

//             if(check(nearestThief,m)){
//                 ans=m;
//                 l=m+1;
//             }
//             else r=m-1;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int n;
    
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    bool check(vector<vector<int>>& distNearestThief, int sf) {
        queue<pair<int, int>> que;

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        //0,0 --> n-1, n-1
        que.push({0, 0});
        visited[0][0] = true;

        if(distNearestThief[0][0] < sf)
            return false;

        while(!que.empty()) {
            int curr_i = que.front().first;
            int curr_j = que.front().second;

            que.pop();

            if(curr_i == n-1 && curr_j == n-1) {
                return true;
            }

            for(vector<int>& dir : directions) {
                int new_i = curr_i + dir[0];
                int new_j = curr_j + dir[1];

                if(new_i >= 0 && new_i < n && new_j >= 0 && new_j < n && visited[new_i][new_j] != true) {
                    if(distNearestThief[new_i][new_j] < sf) {
                        continue; //reject this cell
                    }
                    que.push({new_i, new_j});
                    visited[new_i][new_j] = true;
                }

            }
        }

        return false;
        
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();

        //Step-1 Precalculation of distNearestThief - for each cell
        vector<vector<int>> distNearestThief(n, vector<int>(n, -1));
        queue<pair<int, int>> que;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        //push all cells in queue where theives are present
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    que.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        int level = 0;
        while(!que.empty()) {
            int size = que.size();

            while(size--) {
                int curr_i = que.front().first;
                int curr_j = que.front().second;
                que.pop();
                distNearestThief[curr_i][curr_j] = level;
                for(vector<int>& dir : directions) {
                    int new_i = curr_i + dir[0];
                    int new_j = curr_j + dir[1];

                    if(new_i < 0 || new_i >= n || new_j < 0 || new_j >= n || visited[new_i][new_j]) {
                        continue;
                    }

                    que.push({new_i, new_j});
                    visited[new_i][new_j] = true;

                }

            }
            level++;
        }

        //Step-2 Apply binary search on SF
        int l = 0;
        int r = 400;
        int result = 0;

        while(l <= r) {
            int mid_sf = l + (r-l)/2;

            if(check(distNearestThief, mid_sf)) {
                result = mid_sf;
                l = mid_sf+1;
            } else {
                r = mid_sf-1;
            }
        }

        return result;
        
    }
};