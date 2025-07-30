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
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
        for(int i=0;i<n;i++){
            int xi=stones[i][0];
            int yi=stones[i][1];
            for(int j=i+1;j<n;j++){
                int xj=stones[j][0];
                int yj=stones[j][1];
                if(xi==xj or yi==yj) Union(i,j);
            }
        }
        unordered_set<int> unique_parent;
        for(int i=0;i<n;i++) unique_parent.insert(find(i));
        return n-unique_parent.size();
    }
};