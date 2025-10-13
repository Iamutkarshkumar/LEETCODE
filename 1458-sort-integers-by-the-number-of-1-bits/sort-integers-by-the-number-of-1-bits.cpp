using p=pair<int,int>;
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        priority_queue<p,vector<p>,greater<p>> pq;
        vector<int> ans;
        for(auto ele: arr) pq.push({__builtin_popcount(ele),ele});
        while(not pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};