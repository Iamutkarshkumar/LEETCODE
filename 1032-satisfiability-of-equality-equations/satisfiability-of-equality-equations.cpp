class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int i){
        if(parent[i]==i) return i;
        return parent[i]=find(parent[i]);
    }
    void Union(int x,int y){
        int parent_x=find(x);
        int parent_y=find(y);

        if(rank[parent_x]>rank[parent_y]) parent[parent_y]=parent_x;
        else if(rank[parent_x]<rank[parent_y]) parent[parent_x]=parent_y;
        else{
            parent[parent_y]=parent_x;
            rank[parent_x]++;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26);
        for(int i=0;i<26;i++){
            parent[i]=i;
            rank[i]=0;
        }
        for(auto ele: equations){
            if(ele[1]=='='){
                Union(ele[0]-'a',ele[3]-'a');
            }
        }
        for(auto ele: equations){
            if(ele[1]=='!'){
                if(find(ele[0]-'a')==find(ele[3]-'a')) return false;
            }
        }
        return true;
    }
};