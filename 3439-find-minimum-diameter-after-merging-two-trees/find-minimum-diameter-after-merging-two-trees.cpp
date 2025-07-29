class Solution {
public:
    // Returns {farthest_node, distance} from start node
    pair<int, int> bfs(int start, const vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> dist(n, -1); // -1 means unvisited
        queue<int> q;
        q.push(start);
        dist[start] = 0;
        int farthest = start;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                    if (dist[v] > dist[farthest]) {
                        farthest = v;
                    }
                }
            }
        }
        return {farthest, dist[farthest]};
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1,vector<vector<int>>& edges2) {
        int n1=edges1.size()+1;
        int n2=edges2.size()+1;
        vector<vector<int>> adj1(n1),adj2(n2);
        for (const auto& e : edges1) {
            adj1[e[0]].push_back(e[1]);
            adj1[e[1]].push_back(e[0]);
        }
        for (const auto& e : edges2) {
            adj2[e[0]].push_back(e[1]);
            adj2[e[1]].push_back(e[0]);
        }
        auto [B1, _] = bfs(0, adj1);
        auto [A1, diameter1] = bfs(B1, adj1);
        int x=(diameter1+1)/2;
        auto [B2, _] = bfs(0, adj2);
        auto [A2, diameter2] = bfs(B2, adj2);
        int y=(diameter2+1)/2;
        return max({x+y+1,diameter1,diameter2});
    }
};