class Solution {
  public:
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto &ele: edges){
            adj[ele.first].push_back(ele.second);
            adj[ele.second].push_back(ele.first);
        }
        return adj;
    }
};