class Solution {
public:
    int n;
    void DFS(vector<vector<int>>& isConnected,int u,vector<bool>& visited){
        visited[u]=true;
        for(int v=0;v<n;v++){
            if(!visited[v] and isConnected[u][v]==1) DFS(isConnected,v,visited);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n=isConnected.size();
        vector<bool> visited(n,false);
        int numberOfTimesDfsCalled=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                numberOfTimesDfsCalled++;
                DFS(isConnected,i,visited);
            }
        }
        return numberOfTimesDfsCalled;
    }
};


// class Solution {
// public:
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int n=isConnected.size();
//         vector<int> visited(n,false);
//         queue<int> q;
//         int numberOfTimesBfsCalled=0;
//         for(int i=0;i<n;i++){
//             if(!visited[i]){
//                 numberOfTimesBfsCalled++;
//                 q.push(i);
//                 visited[i]=true;
//                 while(!q.empty()){
//                     int u=q.front();q.pop();
//                     for(int v=0;v<n;v++){
//                         if(!visited[v] and isConnected[u][v]==1){
//                             q.push(v);
//                             visited[v]=true;
//                         }
//                     }
//                 }
//             }
//         }
//         return numberOfTimesBfsCalled;
//     }
// };