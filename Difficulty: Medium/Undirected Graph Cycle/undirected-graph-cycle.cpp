class Solution {
  public:
    // DFS helper: returns true if a cycle is found from node u
    bool isCycleDFS(const vector<vector<int>>& adj, int u, vector<bool>& visited, int parent) {
        visited[u] = true;
        for(int v : adj[u]) {
            if(v == parent) 
                continue;
            if(visited[v]) 
                return true;
            if(isCycleDFS(adj, v, visited, u)) 
                return true;
        }
        return false;
    }

    // edges: list of M pairs {u,v} for an undirected graph on V vertices
    bool isCycle(int V, vector<vector<int>>& edges) {
        // 1) build adjacency list
        vector<vector<int>> adj(V);
        for(auto &e : edges){
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // 2) run DFS on each component
        vector<bool> visited(V, false);
        for(int i = 0; i < V; i++){
            if(!visited[i] && isCycleDFS(adj, i, visited, -1))
                return true;
        }
        return false;
    }
};

// class Solution {
//   public:
//     vector<int> parent;
//     vector<int> rank;
//     int find(int i){
//         if(parent[i]==i) return i;
//         return parent[i]=find(parent[i]);
//     }
//     void Union(int x,int y){
//         int parent_x=find(x);
//         int parent_y=find(y);
        
//         if(rank[parent_x]>rank[parent_y]) parent[parent_y]=parent_x;
//         else if(rank[parent_x]<rank[parent_y]) parent[parent_x]=parent_y;
//         else{
//             parent[parent_y]=parent_x;
//             rank[parent_x]++;
//         }
//     }
//     bool isCycle(int V, vector<vector<int>>& edges) {
//         parent.resize(V);
//         rank.resize(V);
        
//         for(int i=0;i<V;i++){
//             parent[i]=i;
//             rank[i]=0;
//         }
//         for(auto ele: edges){
//             int u=ele[0];
//             int v=ele[1];
//             if(u<v){
//                 int parent_u=find(u);
//                 int parent_v=find(v);
//                 if(parent_u==parent_v) return true;
//                 Union(u,v);
//             }
            
//         }
//         return false;
        
//     }
// };