class Solution {
  public:
    void BFS(vector<vector<int>> &adj,int u,vector<int>& result,vector<bool>& visited){
        queue<int> qu;
        qu.push(u);
        visited[u]=true;
        result.push_back(u);
        while(!qu.empty()){
            int u=qu.front();
            qu.pop();
            for(int v: adj[u]){
                if(!visited[v]){
                    qu.push(v);
                    visited[v]=true;
                    result.push_back(v);
                }
            }
        }
    }
    vector<int> bfs(vector<vector<int>> &adj) {
        int V=adj.size();
        vector<int> result;
        vector<bool> visited(V,false);
        BFS(adj,0,result,visited);
        return result;
        
    }
};

// class Solution {
//   public:
//     // Function to return Breadth First Traversal of given graph.
//     vector<int> bfs(vector<vector<int>> &adj) {
//         int n=adj.size();
//         vector<bool> visited(n,false);
//         queue<int> qu;
//         vector<int> ans;
//         qu.push(0);
//         visited[0]=true;
//         while(!qu.empty()){
//             int u=qu.front();
//             qu.pop();
//             ans.push_back(u);
            
//             for(auto ele: adj[u]) {
//                 if(! visited[ele]){
//                     visited[ele]=true;
//                     qu.push(ele);
//                 }
                
//             }
//         }
//         return ans;
        
//     }
// };