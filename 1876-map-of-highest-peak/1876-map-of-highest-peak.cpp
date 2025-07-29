class Solution {
public:
    vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}}; //down, up, right, left
    bool isSafe(int m,int n,int x,int y){
        return x>=0 and x<m and y>=0 and y<n;
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        queue<pair<int, int>> que;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]==1){
                    ans[i][j]=0;
                    que.push({i,j});
                }
            }
        }
        while(!que.empty()){
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            for(auto dir: directions){
                int new_x = x + dir[0];
                int new_y = y + dir[1];
                if(isSafe(m, n, new_x, new_y) && ans[new_x][new_y] == -1){
                    ans[new_x][new_y] = ans[x][y] + 1; //increment height
                    que.push({new_x, new_y});
                }
            }
        }
        return ans;
    }
};
// class Solution {
// public:
//     #define pii pair<int,int> 
//     bool isValid(int& x, int& y,int& m, int& n){
//         return (x>=0 and x<m and y>=0 and y<n);
//     }
//     vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
//         queue<pii> q;//row,col,height
//         int m=isWater.size();
//         int n=isWater[0].size();
//         vector<vector<int>> height(m,vector<int>(n,0));

//         //step 1- push all start points for multi source bfs
//         vector<vector<bool>> visited(m,vector<bool>(n,false));
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(isWater[i][j]==1){
//                     q.push(make_pair(i,j));
//                     visited[i][j]=true;
//                 }
//             }
//         }
//         //step 2- multi source bfs levelorder
//         vector<int> dir={-1,0,1,0,-1};//4 directional calls- URDL
//         int level=0;
//         while(!q.empty()){
//             int size=q.size();
//             for(int i=0;i<size;i++){
//                 pii curr=q.front();
//                 q.pop();

//                 int x=curr.first;
//                 int y=curr.second;
//                 for(int d=0;d<4;d++){
//                     int newX= x+dir[d];
//                     int newY= y+dir[d+1];
//                     if(isValid(newX,newY,m,n) and !visited[newX][newY]){
//                         q.push(make_pair(newX,newY));
//                         height[newX][newY]=1+level;
//                         visited[newX][newY]=true;
//                     }
//                 }
//             }
//             level++;

//         }
//         return height;
//     }
// };