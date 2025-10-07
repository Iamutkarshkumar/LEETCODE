class Solution{
public:
    vector<int> avoidFlood(vector<int>& rains){
        int n=rains.size();
        vector<int> ans(n,1);
        unordered_map<int,int> last; // lake -> last rain index
        set<int> zeros; // indices of available dry days
        for(int i=0;i<n;i++){
            if(rains[i]>0){
                int lake=rains[i];
                ans[i]=-1;
                if(last.count(lake)){
                    auto it=zeros.upper_bound(last[lake]);
                    if(it==zeros.end()) return {};
                    ans[*it]=lake;
                    zeros.erase(it);
                }
                last[lake]=i;
            } else {
                zeros.insert(i);
            }
        }
        return ans;
    }
};
