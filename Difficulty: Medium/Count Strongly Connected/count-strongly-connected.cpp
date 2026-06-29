class Solution {
  public:
    void DFS1(vector<vector<int>>& adj,int u,vector<bool>& visited,stack<int>& st){
        visited[u]=true;
        for(int v: adj[u]){
            if(!visited[v]) DFS1(adj,v,visited,st);
        }
        st.push(u);
    }
    void DFS2(vector<vector<int>>& adj,int u,vector<bool>& visited,stack<int>& st){
        visited[u]=true;
        for(int v: adj[u]){
            if(!visited[v]) DFS2(adj,v,visited,st);
        }
    }
    int kosaraju(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for(auto edge: edges){
            int u=edge[0],v=edge[1];
            adj[u].push_back(v);
        }
        //step 1: topological order
        stack<int> st;
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]) DFS1(adj,i,visited,st);
        }
        
        //step 2: reverse the edges
        vector<vector<int>> adjReversed(V);
        for(auto edge: edges){
            int u=edge[0],v=edge[1];
            adjReversed[v].push_back(u);
        }
        
        //step 3: DFS on reversed graph in order of stack
        visited.assign(V,false);
        int count=0;
        while(!st.empty()){
            int u=st.top();st.pop();
            if(!visited[u]){
                count++;
                DFS2(adjReversed,u,visited,st);
            }
        }
        return count;
    }
};