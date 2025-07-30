
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
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        parent.resize(V);
        rank.resize(V,0);
        
        vector<vector<int>> ans;
        
        for(int i=0;i<V;i++) parent[i]=i;
        
        for(auto ele: edges){
            if(find(ele[0])!=find(ele[1])) Union(ele[0],ele[1]);
        }
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<V;i++){
            mp[find(i)].push_back(i);
        }
        for(auto ele: mp){
            ans.push_back(ele.second);
        }
        return ans;
    }
};
