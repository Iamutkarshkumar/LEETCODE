class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs){ 
        int n=logs.size();
        int base=INT_MAX,last=INT_MIN;
        for(auto& ele: logs){
            base=min(base,ele[0]);
            last=max(last,ele[1]);
        }
        int DATsize=last-base+2;
        vector<int> v(DATsize,0);
        for(auto ele: logs){
            v[ele[0]-base]+=1;
            v[ele[1]-base]-=1;
        }
        for(int i=1;i<DATsize;i++) v[i]+=v[i-1];
        int idxMaxEle=max_element(begin(v),end(v))-begin(v);
        return base+idxMaxEle;
    }
};