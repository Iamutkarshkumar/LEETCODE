using ll=long long;
class Solution {
public:
    vector<int> parent,rank;
    int find(int i){
        if(i==parent[i]) return i;
        return parent[i]=find(parent[i]);//path compression
    }
    void Union(int x,int y){
        int xPar=find(x);
        int yPar=find(y);
        if(rank[xPar]>rank[yPar]) parent[yPar]=xPar;
        else if(rank[yPar]>rank[xPar]) parent[xPar]=yPar;
        else{
            parent[yPar]=xPar;
            rank[xPar]++;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
        for(auto ele: edges){
            if(find(ele[0]) != find(ele[1])) Union(ele[0],ele[1]);
        }
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) mp[find(i)]++;
        ll ans=0,total=n;
        for(auto &[root,sz]:mp){
            total-=sz;
            ans+=(ll)sz*total;
        }
        return ans;
    }
};