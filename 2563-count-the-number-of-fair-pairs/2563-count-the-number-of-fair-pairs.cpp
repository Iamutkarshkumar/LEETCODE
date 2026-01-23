using ll=long long;
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(begin(nums),end(nums));
        ll ans=0;
        ll n=nums.size();
        for(ll i=0;i<n;i++){
            ll lb=lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i])-begin(nums);
            ll ub=upper_bound(nums.begin()+i+1,nums.end(),upper-nums[i])-begin(nums);
            ans+=(ub-lb);
        }
        return ans;
    }
};