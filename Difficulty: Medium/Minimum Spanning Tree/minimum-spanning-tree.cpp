// Kruskal's Algorithm:
// A greedy algorithm to find the minimum spanning tree (MST) of a weighted connected graph.
// It sorts all edges by weight and adds them one by one to the MST, skipping edges that would form a cycle.
// Uses a disjoint-set (union-find) data structure to efficiently detect cycles.
// Ensures all vertices are connected with minimum total edge weight and no cycles.

class Solution {
  public:
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
    int spanningTree(int V, vector<vector<int>> edges[]) {
        vector<vector<int>> vec;
        for(int u=0;u<V;u++){
            for(auto temp: edges[u]){
                int v=temp[0];
                int wt=temp[1];
                vec.push_back({u,v,wt});
            }
        }
        sort(vec.begin(),vec.end(),cmp);
        return kruskal(vec);
    }
};