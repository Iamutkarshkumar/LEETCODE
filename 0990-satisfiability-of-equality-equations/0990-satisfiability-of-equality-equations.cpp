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
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26,0);
        for(int i=0;i<26;i++) parent[i]=i;

        for(string& ele: equations){
            if(ele[1]=='=') Union(ele[0]-'a',ele[3]-'a');
        }
        for(string& ele: equations){
            if(ele[1]=='!' and find(ele[0]-'a')==find(ele[3]-'a')) return false;
        }
        return true;
    }
};