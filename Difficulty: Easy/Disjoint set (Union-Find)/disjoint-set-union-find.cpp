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
        if(parX!=parY) parent[parX]=parY;
    }
    vector<int> DSU(int n, vector<vector<int>>& queries) {
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++) parent[i]=i;
        
        vector<int> ans;
        for(vector<int>& vec: queries){
            if(vec[0]==1) Union(vec[1],vec[2]);
            else ans.push_back(find(vec[1]));
        }
        return ans;
    }
};