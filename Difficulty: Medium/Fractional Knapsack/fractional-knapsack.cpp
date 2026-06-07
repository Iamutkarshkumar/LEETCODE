class Solution {
  public:
    static bool cmp(pair<int,int>& a,pair<int,int>& b){
        return 1.0*a.first/a.second >=1.0*b.first/b.second;
    }
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n=val.size();
        vector<pair<int,int>> perUnit;
        for(int i=0;i<n;i++){
            perUnit.push_back(make_pair(val[i],wt[i]));
        }
        sort(begin(perUnit),end(perUnit),cmp);
        int i=0;
        double profit=0;
        while(i<n and capacity>0){
            double rate=1.0*perUnit[i].first/perUnit[i].second;
            if(perUnit[i].second<=capacity){
                capacity-=perUnit[i].second;
                profit+=perUnit[i].first;
            }
            else{
                profit+=rate*capacity;
                capacity=0;
            } 
            i++;
        }
        return profit;
    }
};
