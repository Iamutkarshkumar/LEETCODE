class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int i){
        if(parent[i]==i) return i;
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n-1) return -1;
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++){
            rank[i]=0;
            parent[i]=i;
        }
        int components=n;
        for(auto ele: connections){
            if(find(ele[0])!=find(ele[1])){ Union(ele[0],ele[1]);components--;}
        }
        return components-1;
    }
};