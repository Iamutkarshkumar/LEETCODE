// Strongly Connected Components (SCCs):
// In a directed graph, an SCC is a group of vertices where 
// every vertex is reachable from every other vertex in the group.

// Steps of Kosaraju's Algorithm:
// 1. Store vertices in a stack in topological order for original graph.
// 2. Flip all edges of the graph to get the transpose.
// 3. Pop vertices one by one from the stack and do DFS on the transposed graph.
//    Each DFS traversal gives one strongly connected component

class Solution {
  public:
    void dfsFill(int u,vector<vector<int>> &adj,vector<bool>& visited,stack<int>& st){
        visited[u]=true;
        for(auto v: adj[u]){
            if(!visited[v]){
                dfsFill(v,adj,visited,st);
            }
        }
        st.push(u);
    }
    int kosaraju(vector<vector<int>> &adj) {
        // step 1: topological order in stack
        int V = adj.size();
        stack<int> st;
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfsFill(i, adj, visited, st);
            }
        }
        // step 2: transpose the graph
        vector<vector<int>> adjReversed(V);
        for(int u=0;u<V;u++){
            for(auto v: adj[u]){
                adjReversed[v].push_back(u);
            }
        }
        // step 3: DFS on transposed graph in order of stack
        int count=0;
        visited.assign(V, false); // reset visited for second DFS
        while(!st.empty()){
            int u=st.top();
            st.pop();
            if(!visited[u]){
                count++;
                dfsFill(u, adjReversed, visited, st);
            }
        }
        return count; // number of strongly connected components
    }
};