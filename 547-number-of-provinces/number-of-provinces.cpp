class Solution {
public:
    void dfs(unordered_map<int,vector<int>>& adj,int u,vector<int>& visited){
        visited[u]=true;
        for(auto &v: adj[u]){
            if(!visited[v]){
                dfs(adj,v,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        unordered_map<int,vector<int>> adj;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> visited(n,0);
        int count=0;

        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(adj,i,visited);
            }
        }
        return count;
    }
};