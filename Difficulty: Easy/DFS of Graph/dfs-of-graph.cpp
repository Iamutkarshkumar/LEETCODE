class Solution {
  public:
    void DFS(vector<vector<int>>& adj,int u,vector<int>& result,vector<bool>& visited){
        if(visited[u]) return;
        visited[u]=true;
        result.push_back(u);
        for(int v: adj[u]){
            if(!visited[v]) DFS(adj,v,result,visited);
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int> result;
        vector<bool> visited(n,false);
        DFS(adj,0,result,visited);
        return result;
    }
};
#include <bits/stdc++.h>
using namespace std;

// ------------------ Solution Class ------------------
// class Solution {
// public:
//     void DFS(const vector<vector<int>>& adj,
//              int u,
//              vector<int>& result,
//              vector<bool>& visited)
//     {
//         if (visited[u]) return;
//         visited[u] = true;
//         result.push_back(u);
//         for (int v : adj[u]) {
//             if (!visited[v])
//                 DFS(adj, v, result, visited);
//         }
//     }

//     vector<int> dfs(const vector<vector<int>>& adj) {
//         int n = adj.size();
//         vector<int> result;
//         vector<bool> visited(n, false);
//         DFS(adj, 0, result, visited);
//         return result;
//     }
// };
// // -----------------------------------------------------

int main() {

    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj(V);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        // assuming 0‑based nodes; if input is 1‑based, do u--, v-- here
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Solution solver;               // now the compiler knows about Solution
    vector<int> traversal = solver.dfs(adj);

    for (int node : traversal)
        cout << node << ' ';
    cout << '\n';

    return 0;
}
