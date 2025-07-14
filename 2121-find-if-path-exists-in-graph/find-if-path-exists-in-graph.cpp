class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int i){
        if(i==parent[i]) return i;
        return parent[i]=find(parent[i]);
    }
    void Union(int x,int y){
        int par_x=find(x);
        int par_y=find(y);

        if(rank[par_x]>rank[par_y]) parent[par_y]=par_x;
        else if(rank[par_x]<rank[par_y]) parent[par_x]=par_y;
        else{
            parent[par_y]=par_x;
            rank[par_x]++;
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=0;
        }

        for(auto ele: edges){
            if(find(ele[0])!=find(ele[1])) Union(ele[0],ele[1]);
        }
        return find(source)==find(destination);
    }
};