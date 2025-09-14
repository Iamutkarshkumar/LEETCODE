class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(), nums.end());
        priority_queue<int> pq;
        for(auto x: s) pq.push(x);
        vector<int> ans;
        while(k>0 && !pq.empty()){
            ans.push_back(pq.top()); pq.pop(); k--;
        }
        return ans;
    }
};