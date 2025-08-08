// //Approach-1 (Using LIS) - Recursion + Memoization (TLE) ---> 341 / 345 testcases passed
// //T.C : O(n^2) - prev index for every i
// class Solution {
// public:
//     using ll=long long;
//     unordered_map<string,ll> mp;
//     long long solve(ll idx,ll p,vector<ll>& v){
//         if(idx>=v.size()) return 0;
//         string key = to_string(idx) + "_" + to_string(p);
//         if(mp.find(key) != mp.end()) {
//             return mp[key];
//         }
//         ll take=LLONG_MIN;
//         if(p==-1 or v[idx]>=v[p]){
//             take=(v[idx]+idx)+solve(idx+1,idx,v);
//         }
//         ll skip=solve(idx+1,p,v);
//         if(p!=-1) mp[key] =max(skip,take);
//         return max(skip,take);
//     }
//     long long maxBalancedSubsequenceSum(vector<int>& nums) {
//         ll n=nums.size();
//         int maxele=*max_element(nums.begin(),nums.end());
//         if(maxele<=0) return maxele;
//         vector<ll> v(n);
//         for(int i=0;i<n;i++) v[i]=nums[i]-i;
//         return solve(0,-1,v);
//     }
// };


//  Using Optimal LIS - Similar to Patience Sorting) - Accepted
//Time : O(nlogn)
class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        map<int, long long> mp;

        long long ans = INT_MIN;
        
        for(int i = 0; i < n; i++){
            auto it = mp.upper_bound(nums[i]-i); //Find the element just greater than nums[i]-i;

            long long cur_ans = nums[i];

            if(it != mp.begin()) {
                it--;
                cur_ans += (*it).second;
            }
            mp[nums[i]-i] = max(mp[nums[i]-i], cur_ans);

            it = mp.upper_bound(nums[i]-i);

            while(it != mp.end() && (*it).second <= cur_ans) {
                 mp.erase(it++);
            }

            ans = max(ans, cur_ans);
        }

        return ans;
    }
};