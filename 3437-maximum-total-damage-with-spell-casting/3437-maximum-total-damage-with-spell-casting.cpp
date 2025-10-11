// using ll=long long;
// class Solution {
// public:
//     unordered_map<ll,ll> mp;
//     int n;
//     vector<ll> dp;
//     ll solve(int i,vector<ll>& v){
//         if(i>=n) return 0;
//         if(dp[i]!=-1) return dp[i];
//         ll skip=solve(i+1,v);
//         int j=lower_bound(begin(v)+i+1,end(v),v[i]+3)-begin(v);
//         ll take=mp[v[i]]*v[i] +solve(j,v);
//         return dp[i]=max(take,skip);
//     }
//     long long maximumTotalDamage(vector<int>& power) {
//         for(auto ele: power) mp[ele]++;
//         vector<ll> v(mp.size());
//         for(auto ele: mp) v.push_back(ele.first);
//         sort(begin(v),end(v));
//         n=v.size();
//         dp.assign(n+1,-1);
//         return solve(0,v); 
//     }
// };

class Solution {
public:
    typedef long long ll;
    long long maximumTotalDamage(vector<int>& power) {
        // Step 1: Count frequency of each unique power value
        unordered_map<ll, ll> mp;
        
        for (int &x : power)
            mp[x]++;

        // Step 2: \\Collect and sort unique values
        vector<ll> nums(mp.size());
        for (auto &p : mp)
            nums.push_back(p.first);

        sort(begin(nums), end(nums));

        int n = nums.size();
        vector<ll> t(n, 0);
        //dp[i] = Maximum Total Damage if we start from index i
        
        long long result = INT_MIN;

        for (int i = n - 1; i >= 0; --i) {
            //skip current value
            ll skip = (i + 1 < n) ? t[i + 1] : 0;

            //take current value
            int j   = lower_bound(begin(nums) + i + 1, end(nums), nums[i] + 3) - begin(nums);
            ll take = nums[i] * mp[nums[i]] + ((j < n) ? t[j] : 0);

            t[i]   = max(skip, take);
            result = max(result, t[i]);
        }

        return result;
    }
};


