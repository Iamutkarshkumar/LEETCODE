//using min heap 
// class Solution {
//   public:
//     vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
//         vector<vector<pair<int,int>>> adj(V);
//         for(auto ele: edges){
//             adj[ele[0]].push_back({ele[1],ele[2]});
//             adj[ele[1]].push_back({ele[0],ele[2]});
//         } 
        
//         // pair -> dist , node
//         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
//         vector<int> result(V,INT_MAX);
//         result[src]=0;
//         pq.push({0,src});
//         while(!pq.empty()){
//             auto ele =pq.top();pq.pop();
//             int d=ele.first;
//             int u=ele.second;
//             for(auto ele: adj[u]){
//                 int dist=ele.second;
//                 int v=ele.first;
//                 if(d>result[u]) continue;
//                 if(d+dist<result[v]){
//                     result[v]=d+dist;
//                     pq.push({d+dist,v});
//                 }
//             }
//         }
//         return result;
//     }
// };


//using set
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        vector<vector<pair<int,int>>> adj(V);
        for(auto ele: edges){
            adj[ele[0]].push_back({ele[1],ele[2]});
            adj[ele[1]].push_back({ele[0],ele[2]});
        } 
        
        set<pair<int,int>> st;
        vector<int> result(V,INT_MAX);
        
        result[src]=0;
        st.insert({0,src});
        while(!st.empty()){
            auto ele = *st.begin();st.erase(st.begin());
            int u=ele.second;
            int d=ele.first;
            for(auto node: adj[u]){
                int v=node.first;
                int dist=node.second;
                if(d+dist<result[v]){
                    auto it=st.find({result[v],v});
                    if(it!=st.end()) st.erase(it);
                
                    result[v]=d+dist;
                    st.insert({result[v],v});
                }
            }
        }
        return result;
    }
};