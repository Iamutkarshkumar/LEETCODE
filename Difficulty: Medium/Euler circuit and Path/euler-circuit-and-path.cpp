class Solution {
  public:
    void DFS(vector<vector<int>>& adj,int u,vector<bool>& visited){
        visited[u]=true;
        for(int v: adj[u]){
            if(!visited[v]) DFS(adj,v,visited);
        }
    }
    bool isConnected(int V, vector<vector<int>>& adj){
        int nonZeroDegVertex=-1;
        for(int i=0;i<V;i++){
            if(adj[i].size()>0){
                nonZeroDegVertex=i;
                break;
            }
        }
        vector<bool> visited(V,false);
        //start dfs fron non zero deg index to mark all non zero vertex in that component
        // if all the non zero deg vertex are not in same component then graph cant have euler path
        DFS(adj,nonZeroDegVertex,visited);
        //check all non zero deg vertex marked visited or not
        for(int i=0;i<V;i++){
            if(visited[i]==false and adj[i].size()>0) return false;
        }
        return true;
    }
    int isEulerCircuit(int V, vector<vector<int>>& adj) {
        if(isConnected(V,adj)==false) return 0;
        int oddDegCount=0;
        for(int i=0;i<V;i++){
           if(adj[i].size()%2==1) oddDegCount++;
        }
        if(oddDegCount>2) return 0;
        if(oddDegCount==2) return 1;
        return 2;
        
    }
};