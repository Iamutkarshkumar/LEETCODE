class Solution {
  public:
    bool isCycleDFS(vector<vector<int>>& adj,int u,vector<bool>& visited,vector<bool>& inRecursion){
        visited[u]=true;
        inRecursion[u]=true;
        for(int v: adj[u]){
            if(visited[v]==true and inRecursion[v]==true) return true;
            else if(!visited[v] and isCycleDFS(adj,v,visited,inRecursion)) return true;
        }
        inRecursion[u]=false;
        return false;
    }
    bool isCyclic(int v, vector<vector<int>> &edges) {
        vector<vector<int>> adj(v);
        for(auto ele : edges) adj[ele[0]].push_back(ele[1]);
        
        vector<bool> visited(v,false),inRecursion(v,false);
        
        for(int i=0;i<v;i++){
            if(!visited[i] and isCycleDFS(adj,i,visited,inRecursion)) return true;
        }
        return false;
    }
};