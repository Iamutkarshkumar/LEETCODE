class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int source) {
        set<pair<int,int>> s;
        vector<int> result(V+1,INT_MAX);
        result[source]=0;
        s.insert({0,source});
        vector<vector<pair<int, int>>> adj(V+1);
        for(auto &edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
        while(!s.empty()){
            auto &it = *s.begin();
            int d = it.first;
            int node = it.second;
            s.erase(it);
            for(auto &vec: adj[node]){
                int nextNode = vec.first;
                int wt = vec.second;

                if(d + wt < result[nextNode]) {
                    s.erase({result[nextNode], nextNode}); // Remove old value
                    result[nextNode] = d + wt;
                    s.insert({d+wt, nextNode}); // Insert new value
                }
            }
        }
        return result;
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Run Dijkstra from k on an n‑node graph
        vector<int> dist = dijkstra(n, times, k);
        
        // Check for any unreachable node (still INT_MAX)
        int answer = 0;
        for (int node = 1; node <= n; ++node) {
            if (dist[node] == INT_MAX) 
                return -1;
            answer = max(answer, dist[node]);
        }
        
        return answer;
    }
};
