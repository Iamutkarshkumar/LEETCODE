class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> result(V,1e8);
        result[src]=0;
        //relaxing v-1 times
        for(int relax=1;relax<=V-1;relax++){
            for(auto &edge: edges){
                int u=edge[0];
                int v=edge[1];
                int wt=edge[2];
                if(result[u]!=1e8 and result[u]+wt<result[v]){
                    result[v]=result[u]+wt;
                }
            }
        }
        
        // relaxing 1 more time to check -ve cycle
        
        for(auto &edge: edges){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            if(result[u]!=1e8 and result[u]+wt<result[v]){
                return {-1};
            }
        }
        return result;
    }
};
