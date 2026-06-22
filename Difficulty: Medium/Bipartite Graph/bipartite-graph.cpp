class Solution {
  public:
    bool BFS(vector<vector<int>>& adj,int u,vector<int>& color,int currColor){
        color[u]=currColor;
        queue<int> q;
        q.push(u);
        while(!q.empty()){
            int u=q.front();q.pop();
            for(int v: adj[u]){
                if(color[v]==color[u]) return false;
                if(color[v]==-1 and BFS(adj,v,color,1-currColor)==false) return false;
            }
        }
        return true;
    }
    bool isBipartite(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for(auto ele: edges){
            int u=ele[0],v=ele[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> color(V,-1);
        for(int i=0;i<V;i++){
            if(color[i]==-1 and BFS(adj,i,color,1)==false) return false;
        }
        return true;
    }
};
// class Solution {
//   public:
//     bool DFS(vector<vector<int>>& adj,int u,vector<int>& color,int currColor){
//         color[u]=currColor;
//         for(int v: adj[u]){
//             if(color[u]==color[v]) return false;
//             if(color[v]==-1 and DFS(adj,v,color,1-currColor)==false) return false;
//         }
//         return true;
//     }
//     bool isBipartite(int V, vector<vector<int>> &edges) {
//         vector<vector<int>> adj(V);
//         for(auto ele: edges){
//             int u=ele[0],v=ele[1];
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }
//         vector<int> color(V,-1);
//         for(int i=0;i<V;i++){
//             if(color[i]==-1 and DFS(adj,i,color,1)==false) return false;
//         } 
//         return true;
//     }
// };