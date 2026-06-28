// Prims algoritm
using pii =pair<int,int>;
class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pii>> adj(V);
        for(auto ele: edges){
            adj[ele[0]].push_back({ele[1],ele[2]});
            adj[ele[1]].push_back({ele[0],ele[2]});
        }
        int sum=0;
        vector<bool> visited(V,false);
        priority_queue<pii,vector<pii>,greater<pii>> pq;// {wt,node}, if want path also we need parent vector too so use {wt,node,par} in pq
        pq.push({0,0});
        while(!pq.empty()){
            int wt=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(visited[node]) continue;
            visited[node]=true;
            sum+=wt;
            for(auto v: adj[node]){
                if(visited[v.first]) continue;
                pq.push({v.second,v.first});
            }
        }
        return sum;
    }
};