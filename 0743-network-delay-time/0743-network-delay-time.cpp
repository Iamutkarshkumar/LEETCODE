class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto ele: times) adj[ele[0]].push_back({ele[1],ele[2]});

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; 
        vector<int> result(n+1,INT_MAX);
        result[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            int u=pq.top().second;
            int d=pq.top().first;
            pq.pop();
            for(auto node : adj[u]){
                int v=node.first;
                int dist=node.second;
                if(dist+d<result[v]){
                    pq.push({d+dist,v});
                    result[v]=d+dist;
                }
            }
        }
        int mxTime=*max_element(begin(result)+1,end(result));
        return mxTime==INT_MAX ? -1 : mxTime;
    }
};