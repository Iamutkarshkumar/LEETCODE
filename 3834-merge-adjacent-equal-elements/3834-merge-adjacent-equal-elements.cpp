using ll=long long;
class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<ll> s;
        for(auto x: nums){
            ll cur=x;
            while(!s.empty() and s.top()==cur){
                cur+=s.top();
                s.pop();
            }
            s.push(cur);
        }
        vector<ll> ans;
        while(!s.empty()){
            ans.push_back(s.top());s.pop();
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};