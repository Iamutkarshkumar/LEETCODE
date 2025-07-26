class Solution {
  public:
    using p=pair<int,int>;
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
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
                int nextNode=ele[0];
                int nextWt=ele[1];
                if(!inMST[nextNode]) {
                    pq.push({nextWt, nextNode}); // Push unvisited adjacent nodes with their weights
                }
            }
        }
        return sum; // Return the total weight of the MST
        
    }
};