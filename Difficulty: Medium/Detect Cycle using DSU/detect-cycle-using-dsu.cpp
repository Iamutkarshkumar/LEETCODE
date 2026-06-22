class Solution {
  public:
    vector<int> parent,rank;
    int find(int i){
        if(i==parent[i]) return i;
        return parent[i]=find(parent[i]); // path compression
    }
    void Union(int x,int y){
        int parX=find(x);
        int parY=find(y);
        if(rank[parX]>rank[parY]) parent[parY]=parX;
        else if(rank[parY]>rank[parX]) parent[parX]=parY;
        else{
            parent[parY]=parX;
            rank[parX]++;
        }
    }
    bool detectCycle(int V, vector<int> adj[]) {
        parent.resize(V);
        rank.resize(V,0);
        for(int i=0;i<V;i++) parent[i]=i;
        
        for(int u=0;u<V;u++){
            for(int &v: adj[u]){
                if(u<v){
                    if(find(u)==find(v)) return true;
                    Union(u,v);
                }
            }
        }
        return false;
    }
};