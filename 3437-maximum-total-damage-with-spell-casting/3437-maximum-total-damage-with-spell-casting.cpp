class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        if(power.empty()) return 0;
        unordered_map<long long,long long> freq;
        for(int x: power) freq[x] += 1;

        // collect unique values sorted
        vector<long long> vals;
        vals.reserve(freq.size());
        for(auto &p: freq) vals.push_back(p.first);
        sort(vals.begin(), vals.end());

        int n = vals.size();
        vector<long long> sum(n);   // sum[i] = vals[i] * count(vals[i])
        for(int i=0;i<n;i++) sum[i] = vals[i] * freq[vals[i]];

        vector<long long> dp(n,0);
        for(int i=0;i<n;i++){
            // find prev index j such that vals[j] <= vals[i]-3
            long long need = vals[i] - 3; // allowed difference > 2 => prev <= vals[i]-3
            int j = -1;
            if(need >= vals[0]) {
                auto it = upper_bound(vals.begin(), vals.begin() + i, need);
                if(it != vals.begin()) j = int(it - vals.begin()) - 1;
            }
            long long take = sum[i] + (j >= 0 ? dp[j] : 0);
            long long skip = (i > 0 ? dp[i-1] : 0);
            dp[i] = max(take, skip);
        }
        return dp[n-1];
    }
};
