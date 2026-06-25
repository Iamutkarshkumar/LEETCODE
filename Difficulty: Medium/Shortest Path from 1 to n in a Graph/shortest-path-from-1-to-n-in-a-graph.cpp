class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto ele: edges){
            adj[ele[0]].push_back({ele[1],ele[2]});
            adj[ele[1]].push_back({ele[0],ele[2]});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> result(n+1,INT_MAX);
        vector<int> parent(n+1);
        for(int i=0;i<n+1;i++) parent[i]=i;
        
        pq.push({0,1});
        result[1]=0;
        parent[1]=1;
        while(!pq.empty()){
            int u=pq.top().second;
            int d=pq.top().first;
            pq.pop();
            for(auto node: adj[u]){
                int v=node.first;
                int dist=node.second;
                if(d+dist<result[v]){
                    pq.push({d+dist,v});
                    result[v]=d+dist;
                    parent[v]=u;
                }
            }
        }
        if(result[n]==INT_MAX) return {-1};

        vector<int> path;
        int i=n;
        while(parent[i]!=i){
            path.push_back(i);
            i=parent[i];
        }
        path.push_back(1);
        path.push_back(result[n]);
        reverse(path.begin(),path.end());
        
        return path;
        
    }
};