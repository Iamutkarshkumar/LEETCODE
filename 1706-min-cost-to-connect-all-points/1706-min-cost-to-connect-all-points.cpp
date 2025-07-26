class Solution {
public:
    using p=pair<int,int>;
    vector<int> parent;
    vector<int> rank;
    int find(int i){
        if(i==parent[i]) return i;
        return parent[i]=find(parent[i]); //path compression
    }
    void Union(int x,int y){
        int parent_x=find(x);
        int parent_y=find(y);

        if(rank[parent_x]>rank[parent_y]) parent[parent_y]=parent_x;
        else if(rank[parent_y]>rank[parent_x]) parent[parent_x]=parent_y;
        else{
            parent[parent_y]=parent_x; //we made x as the parent
            rank[parent_x]++; 
        }
    }
    int kruskal(vector<vector<int>>& vec){
        int sum=0;
        int n = vec.size();
        parent.resize(n);
        rank.resize(n, 0);
        for(int i=0;i<n;i++){
            parent[i]=i; // initialize parent[i]=i
        }
        for(auto temp:vec){
            int u=temp[0];
            int v=temp[1];
            int wt=temp[2];

            int par_u=find(u);
            int par_v=find(v);
            if(par_u!=par_v){
                Union(u, v); // Union the sets
                sum+=wt; // Add weight to the total sum
            }
        }
        return sum; // Return the total weight of the MST
    }
    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[2] < b[2]; // Compare edges by weight
    }
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<p>>& adj) {
        vector<vector<int>> vec;
        for(int u=0;u<V;u++){
            for(auto temp: adj[u]){
                int v=temp.first;
                int wt=temp.second;
                vec.push_back({u,v,wt});
            }
        }
        sort(vec.begin(),vec.end(),cmp);
        return kruskal(vec);
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
// class Solution {
// public:
//     using p=pair<int,int>;
//     int spanningTree(int V, vector<vector<p>>& adj) {
//         vector<bool> inMST(V, false);
//         int sum=0;
//         priority_queue<p, vector<p>, greater<p>> pq;

//         pq.push({0,0}); // {weight, vertex}
//         while(!pq.empty()){
//             int wt=pq.top().first;
//             int node=pq.top().second;
//             pq.pop();
//             if(inMST[node]) continue; // Skip if already in MST
//             inMST[node] = true; // Mark this node as included in MST
//             sum += wt; // Add weight to the total sum

//             for(auto ele: adj[node]){
//                 int nextNode=ele.first;
//                 int nextWt=ele.second;
//                 if(!inMST[nextNode]) {
//                     pq.push({nextWt, nextNode}); // Push unvisited adjacent nodes with their weights
//                 }
//             }
//         }
//         return sum; // Return the total weight of the MST
//     }
//     int minCostConnectPoints(vector<vector<int>>& points) {
//         int V=points.size();
//         vector<vector<p>> adj(V);
//         for(int i=0;i<V;i++){
//             for(int j=i+1;j<V;j++){
//                 int dist=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
//                 adj[i].push_back({j,dist});
//                 adj[j].push_back({i,dist});
//             }
//         }
//         return spanningTree(V,adj);
//     }
// };