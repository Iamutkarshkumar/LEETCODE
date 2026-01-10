using ll=long long;
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<ll> s,e;
        for(auto ele: flowers){
            s.push_back(ele[0]);
            e.push_back(ele[1]);
        } 
        sort(begin(s),end(s));
        sort(begin(e),end(e));
        vector<int> ans;
        for(auto ele: people){
            int ub= upper_bound(begin(s),end(s),ele)-begin(s);
            int lb= lower_bound(begin(e),end(e),ele)-begin(e);
            ans.push_back(ub-lb);
        }
        return ans;
    }
};