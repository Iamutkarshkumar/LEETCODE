class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        int n=adj.size();
        vector<int> visited(n,0);
        queue<int> qu;
        vector<int> ans;
        qu.push(0);
        visited[0]=1;
        while(!qu.empty()){
            int u=qu.front();
            qu.pop();
            ans.push_back(u);
            
            for(auto ele: adj[u]) {
                if(! visited[ele]){
                    visited[ele]=1;
                    qu.push(ele);
                }
                
            }
        }
        return ans;
        
    }
};