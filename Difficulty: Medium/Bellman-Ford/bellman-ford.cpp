// Bellman-Ford Algorithm:
// Used to find shortest paths from a single source in graphs with negative edge weights.
// It works for both directed and undirected graphs and detects negative cycles.
// For undirected graph convert it to directed graph by adding both directions.
// But in undirected graphs, the edge weights must be non-negative.
// Unlike Dijkstra's algorithm, Bellman-Ford handles negative weights and cycles.
// Dijkstra fails with negative weights, while Bellman-Ford is slower but more versatile.
// Do relaxation for all edges V-1 times, where V is the number of vertices.
// Order of relaxation of edges must remain the same in each iteration.

//-ve cycle detection: If we can relax an edge after V-1 iterations, a -ve cycle exists.

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V,1e8);
        dist[src]=0;
        for(int i=1;i<=V-1;i++){
            for(auto edge: edges){
                int u= edge[0];
                int v= edge[1];
                int wt= edge[2];
                if(dist[u]!=1e8 and dist[u]+wt < dist[v]){
                    dist[v]=dist[u]+wt;
                }
            }
        }
        // Check for negative weight cycles
        bool flag=false;
        for(auto edge: edges){
            int u= edge[0];
            int v= edge[1];
            int wt= edge[2];
            if(dist[u]!=1e8 and dist[u]+wt < dist[v]){
                flag=true;
                break;
            }
        }
        if (flag) return {-1};
        return dist;
    }
};