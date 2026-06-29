// Prims algoritm
// using pii =pair<int,int>;
// class Solution {
//   public:
//     int spanningTree(int V, vector<vector<int>>& edges) {
//         vector<vector<pii>> adj(V);
//         for(auto ele: edges){
//             adj[ele[0]].push_back({ele[1],ele[2]});
//             adj[ele[1]].push_back({ele[0],ele[2]});
//         }
//         int sum=0;
//         vector<bool> inMST(V,false);
//         priority_queue<pii,vector<pii>,greater<pii>> pq;// {wt,node}, if want path also we need parent vector too so use {wt,node,par} in pq
//         pq.push({0,0});
//         while(!pq.empty()){
//             int wt=pq.top().first;
//             int node=pq.top().second;
//             pq.pop();
//             if(inMST[node]) continue;
//             inMST[node]=true;
//             sum+=wt;
//             for(auto v: adj[node]){
//                 if(inMST[v.first]) continue;
//                 pq.push({v.second,v.first});
//             }
//         }
//         return sum;
//     }
// };



//using kruskal's algo
class Solution {
  public:
    vector<int> parent,rank;
    int find(int i){
        if(i==parent[i]) return i;
        return parent[i]=find(parent[i]);
    }
    void Union(int x,int y){
        int parX=find(x);
        int parY=find(y);
        if(rank[parX]>rank[parY]) parent[parY]=parX;
        else if(rank[parX]<rank[parY]) parent[parX]=parY;
        else{
            parent[parY]=parX;
            rank[parX]++;
        }
    }
    static bool cmp(vector<int>& a,vector<int>& b){
        return a[2]<b[2];
    }
    int spanningTree(int V, vector<vector<int>>& edges) {
        parent.resize(V);
        rank.resize(V,0);
        for(int i=0;i<V;i++) parent[i]=i;
        int sum=0;
        sort(edges.begin(),edges.end(),cmp); // sort in ascending order acc to weights
        for(auto edge: edges){
            int u=edge[0],v=edge[1],wt=edge[2];
            if(find(u)!=find(v)){
                sum+=wt;
                Union(u,v);
            }
        }
        return sum;
    }
};