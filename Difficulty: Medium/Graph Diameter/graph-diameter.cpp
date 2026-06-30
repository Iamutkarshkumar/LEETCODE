class Solution {
  public:
    vector<int> BFS(vector<vector<int>>& adj,int u,vector<bool>& visited){
        visited[u]=true;
        queue<int> q;
        q.push(u);
        int dia=0;
        int farthestNode=u;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                int u=q.front();
                q.pop();
                for(int v: adj[u]){
                    if(!visited[v]){
                        visited[v]=true;
                        q.push(v);
                        farthestNode=v;
                    }
                }
            }
            dia++;
        }
        return {dia-1,farthestNode};
    }
    int diameter(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto ele: edges){
            adj[ele[0]].push_back(ele[1]);
            adj[ele[1]].push_back(ele[0]);
        }
        vector<bool> visited(V,false);
        vector<int> oneEndOfDia=BFS(adj,0,visited);
        visited.assign(V,false);
        vector<int> dia=BFS(adj,oneEndOfDia[1],visited);
        return dia[0];
    }
};
