class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    vector<int> enemy;
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
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        parent.resize(n+1);
        rank.resize(n+1,0);
        enemy.resize(n+1,0);
        for(int i=0;i<n+1;i++) parent[i]=i;
        for(auto x: dislikes){
            int a=x[0];
            int b=x[1];
            int ea=enemy[a];
            int eb=enemy[b];
            if (find(a) == find(b)) return false;
            // Union a with b's enemies
            if (eb) Union(a, eb);
            // Union b with a's enemies
            if (ea) Union(b, ea);

            // Now set their enemies to each other
            enemy[a] = find(b);
            enemy[b] = find(a);
        }
        return true;
    }
};