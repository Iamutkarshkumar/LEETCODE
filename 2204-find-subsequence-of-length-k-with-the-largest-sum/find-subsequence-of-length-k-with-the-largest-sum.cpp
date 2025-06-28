class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        // 1) Use a min‐heap to keep track of the k largest values seen so far
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int x : nums) {
            pq.push(x);
            if (pq.size() > k) pq.pop();
        }
        // 2) Count how many times each of those k values appears
        unordered_map<int,int> cnt;
        while (!pq.empty()) {
            cnt[pq.top()]++;
            pq.pop();
        }
        // 3) Iterate through nums, taking an element if it's in cnt
        vector<int> ans;
        ans.reserve(k);
        for (int x : nums) {
            if (cnt[x] > 0) {
                ans.push_back(x);
                if (--cnt[x] == 0)
                    cnt.erase(x);
            }
        }
        return ans;
    }
};
