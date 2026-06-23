//using min heap 
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        vector<vector<pair<int,int>>> adj(V);
        for(auto ele: edges){
            adj[ele[0]].push_back({ele[1],ele[2]});
            adj[ele[1]].push_back({ele[0],ele[2]});
        } 
        
        // pair -> dist , node
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> result(V,INT_MAX);
        result[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
            auto ele =pq.top();pq.pop();
            int d=ele.first;
            int u=ele.second;
            for(auto ele: adj[u]){
                int dist=ele.second;
                int v=ele.first;
                if(d>result[u]) continue;
                if(d+dist<result[v]){
                    result[v]=d+dist;
                    pq.push({d+dist,v});
                }
            }
        }
        return result;
    }
};