class Solution {
public:
    using p=pair<int,int>;
    int spanningTree(int V, vector<vector<p>>& adj) {
        vector<bool> inMST(V, false);
        int sum=0;
        priority_queue<p, vector<p>, greater<p>> pq;

        pq.push({0,0}); // {weight, vertex}
        while(!pq.empty()){
            int wt=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(inMST[node]) continue; // Skip if already in MST
            inMST[node] = true; // Mark this node as included in MST
            sum += wt; // Add weight to the total sum

            for(auto ele: adj[node]){
                int nextNode=ele.first;
                int nextWt=ele.second;
                if(!inMST[nextNode]) {
                    pq.push({nextWt, nextNode}); // Push unvisited adjacent nodes with their weights
                }
            }
        }
        return sum; // Return the total weight of the MST
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V=points.size();
        vector<vector<p>> adj(V);
        for(int i=0;i<V;i++){
            for(int j=i+1;j<V;j++){
                int dist=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                adj[i].push_back({j,dist});
                adj[j].push_back({i,dist});
            }
        }
        return spanningTree(V,adj);
    }
};