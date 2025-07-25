// Input: V = 3, edges[][] = [[0, 1, 1], [1, 2, 3], [0, 2, 6]], source = 2
// Output: [4, 3, 0]
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int source) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> result(V,INT_MAX);
        result[source]=0;
        pq.push({0,source});
        vector<vector<pair<int, int>>> adj(V);
        for(auto &edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]}); // Assuming undirected graph
        }
        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto &vec: adj[node]){
                int nextNode= vec.first;
                int wt= vec.second;

                if(d+wt < result[nextNode]) {
                    result[nextNode] = d + wt;
                    pq.push({d+wt, nextNode});
                }
            }
        }
        return result;
    }
};